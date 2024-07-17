from tqdm import tqdm
import json
import os
import numpy as np

def find_test_case_length(dic):
    len_dict = {}
    for key in dic.keys():
        len_public_test_case = len(dic[key]['test_case']['public']['input'])
        len_private_test_case = len(dic[key]['test_case']['private']['input'])
        len_generated_test_case = len(dic[key]['test_case']['generated']['input'])
        len_dict[key] = [len_public_test_case, len_private_test_case, len_generated_test_case]

    return len_dict

def concat_test_case(dic):
    for key in dic.keys():
        dic[key]['test_case'] = {
            'input':[*dic[key]['test_case']['public']['input'], *dic[key]['test_case']['private']['input'], *dic[key]['test_case']['generated']['input']],
            'output':[*dic[key]['test_case']['public']['output'], *dic[key]['test_case']['private']['output'], *dic[key]['test_case']['generated']['output']]
        }

    return dic

def make_numpy(result_json):
    result = result_json['results']
    code_index_list = []
    test_result_list = []
    for single_result in result:
        code_index_list.append(single_result[0])
        test_result_list.append(single_result[1])
    np_test_result = np.array(test_result_list)

    return (code_index_list, np_test_result)

# Selecting appropriate correct codes and test cases

def refine_data(code_index_list, np_test_result, len_list):
    len_public = len_list[0]
    len_private = len_list[1]

    test_length = len_public + len_private

    if (len(code_index_list) != np_test_result.shape[0]):
        adsfasf 
    non_zero_indices = np.where(np.all(np_test_result[:, range(test_length)] != 0, axis=1))[0]
    source_code_index = [code_index_list[source_index] for source_index in non_zero_indices]
    np_source_code = np_test_result[non_zero_indices]
    test_case_index = np.where(np.all(np_source_code != 0, axis=0))[0]

    return test_case_index, source_code_index

def check_result(result_path, len_dict):
    final_test_case = {}
    
    for index, check_file in tqdm(enumerate(os.listdir(result_path)), leave = True):
        pid = check_file.split('_')[-1].split('.json')[0] 
        file_path = os.path.join(result_path, check_file)
        with open(file_path, 'r') as f:
            result_json = json.load(f)

        code_index_list, np_test_result = make_numpy(result_json)
        test_case_index, source_code_index = refine_data(code_index_list, np_test_result, len_dict[pid])

        final_test_case[pid] = [test_case_index.tolist(), source_code_index]

    return final_test_case

def extract_values(indices, raw_test_case, raw_code_pair):
    input_values = raw_test_case['input']
    output_values = raw_test_case['output']
    
    test_case_refine = {
        'input': [input_values[i] for i in indices[0]],
        'output': [output_values[i] for i in indices[0]]
    }
    code_refine = [raw_code_pair[j] for j in indices[1]]

    return test_case_refine, code_refine

def data_filter(final_test_case, data_dict):

    final_test_case_key = final_test_case.keys()

    for key, value in final_test_case.items():
        raw_test_case = data_dict[key]['test_case']
        raw_code_pair = data_dict[key]['code_pair']
        extract_test_case, extract_code = extract_values(value, raw_test_case, raw_code_pair)
        data_dict[key]['test_case'] = extract_test_case
        data_dict[key]['code_pair'] = extract_code

    for key, value in data_dict.items():    
        if key not in final_test_case_key:
            data_dict[key]['test_case'] = {
                'input': [],
                'output': []
            }
    
    del_dict = []

    for key, value in data_dict.items():
        if (len(value['test_case']['input']) == 0) & (len(value['test_case']['output']) == 0):
            del_dict.append(key)
            continue
        if len(value['code_pair']) == 0:
            del_dict.append(key)
            continue

    for del_key in del_dict:
        del data_dict[del_key]

    return data_dict 

def count_test_case(cpp_dict):
    count = 0
    for key, value in cpp_dict.items():
        for single_input in value['test_case']['input']:
            count += len(single_input)
    return count

def count_code(cpp_dict):
    count = 0
    for key, value in cpp_dict.items():
        if len(value['test_case']['input']) != 0:
            count += len(value['code_pair'])

    return count

np.set_printoptions(threshold=np.inf)
curr_path = os.getcwd()

cpp_test_result_path = os.path.join(curr_path, 'cpp_test_source_result')
cpp_valid_result_path = os.path.join(curr_path, 'cpp_valid_source_result')
cpp_train_result_path = os.path.join(curr_path, 'cpp_train_source_result')

cpp_test_gold_filter_path = os.path.join(curr_path, 'cpp_data', 'cpp_test_gold_filtered.json')
cpp_valid_gold_filter_path = os.path.join(curr_path, 'cpp_data', 'cpp_valid_gold_filtered.json')
cpp_train_gold_filter_path = os.path.join(curr_path, 'cpp_data', 'cpp_train_gold_filtered.json')

with open(cpp_test_gold_filter_path, 'r') as f:
    cpp_test = json.load(f)
with open(cpp_valid_gold_filter_path, 'r') as f:
    cpp_valid = json.load(f)
with open(cpp_train_gold_filter_path, 'r') as f:
    cpp_train = json.load(f)

len_cpp_test = find_test_case_length(cpp_test)
len_cpp_valid = find_test_case_length(cpp_valid)
len_cpp_train = find_test_case_length(cpp_train)

# cpp_test = concat_test_case(cpp_test)
# cpp_valid = concat_test_case(cpp_valid)
# cpp_train = concat_test_case(cpp_train)

test_check_result = check_result(cpp_test_result_path, len_cpp_test)
valid_check_result = check_result(cpp_valid_result_path, len_cpp_valid)
train_check_result = check_result(cpp_train_result_path, len_cpp_train)

print(f'# Original test case of test_check_result {count_test_case(cpp_test)}')
print(f'# Original test case of valid_check_result {count_test_case(cpp_valid)}')
print(f'# Original test case of train_check_result {count_test_case(cpp_train)}')

print(f'# Original Code pair of test_check_result {count_code(cpp_test)}')
print(f'# Original Code pair of valid_check_result {count_code(cpp_valid)}')
print(f'# Original Code pair of train_check_result {count_code(cpp_train)}')

source_filter_test = data_filter(test_check_result, cpp_test)
source_filter_valid = data_filter(valid_check_result, cpp_valid)
source_filter_train = data_filter(train_check_result, cpp_train)

print(f'# source filtered test case of test_check_result {count_test_case(source_filter_test)}')
print(f'# source filtered test case of valid_check_result {count_test_case(source_filter_valid)}')
print(f'# source filtered test case of train_check_result {count_test_case(source_filter_train)}')

print(f'# source filtered Code pair of test_check_result {count_code(source_filter_test)}')
print(f'# source filtered Code pair of valid_check_result {count_code(source_filter_valid)}')
print(f'# source filtered Code pair of train_check_result {count_code(source_filter_train)}')

with open(f'./cpp_data/cpp_test_source_filtered.json', 'w') as f:
    json.dump(source_filter_test, f, indent=4)

with open(f'./cpp_data/cpp_valid_source_filtered.json', 'w') as f:
    json.dump(source_filter_valid, f, indent=4)

with open(f'./cpp_data/cpp_train_source_filtered.json', 'w') as f:
    json.dump(source_filter_train, f, indent=4)