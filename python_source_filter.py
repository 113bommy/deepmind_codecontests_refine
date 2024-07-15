from tqdm import tqdm
import json
import os
import numpy as np

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

def select_test_case(np_test_result):
    test_case_index = np.where(np.all(np_test_result != 0, axis=0))[0]
    return test_case_index

def check_result(result_path):
    final_test_case = {}
    
    for index, check_file in tqdm(enumerate(os.listdir(result_path)), leave = True):
        pid = check_file.split('_')[-1].split('.json')[0]

        file_path = os.path.join(result_path, check_file)
        with open(file_path, 'r') as f:
            result_json = json.load(f)

        code_index_list, np_test_result = make_numpy(result_json)
        test_case_index = select_test_case(np_test_result)

        final_test_case[pid] = test_case_index.tolist()

    return final_test_case

def extract_values(indices, values):
    input_values = values['input']
    output_values = values['output']
    
    result = {
        'input': [input_values[i] for i in indices],
        'output': [output_values[i] for i in indices]
    }
    return result

def data_filter(final_test_case, data_dict):

    final_test_case_key = final_test_case.keys()

    for key, value in final_test_case.items():
        raw_test_case = data_dict[key]['test_case']
        extract_test_case = extract_values(value, raw_test_case)
        data_dict[key]['test_case'] = extract_test_case

    for key, value in data_dict.items():    
        if key not in final_test_case_key:
            data_dict[key]['test_case'] = {
                'input': [],
                'output': []
            }
            
    return data_dict

def count_test_case(python_dict):
    count = 0
    for key, value in python_dict.items():
        for single_input in value['test_case']['input']:
            count += len(single_input)
    return count

def count_code(python_dict):
    count = 0
    for key, value in python_dict.items():
        if len(value['test_case']['input']) != 0:
            count += len(value['code_pair'])

    return count

np.set_printoptions(threshold=np.inf)
curr_path = os.getcwd()

python_test_result_path = os.path.join(curr_path, 'python_test_gold_result')
python_valid_result_path = os.path.join(curr_path, 'python_valid_gold_result')
python_train_result_path = os.path.join(curr_path, 'python_train_gold_result')

python_test_refine_path = os.path.join(curr_path, 'python_data', 'python_test_refine.json')
python_valid_refine_path = os.path.join(curr_path, 'python_data', 'python_valid_refine.json')
python_train_refine_path = os.path.join(curr_path, 'python_data', 'python_train_refine.json')

with open(python_test_refine_path, 'r') as f:
    python_test = json.load(f)
with open(python_valid_refine_path, 'r') as f:
    python_valid = json.load(f)
with open(python_train_refine_path, 'r') as f:
    python_train = json.load(f)

python_test = concat_test_case(python_test)
python_valid = concat_test_case(python_valid)
python_train = concat_test_case(python_train)

test_check_result = check_result(python_test_result_path)
valid_check_result = check_result(python_valid_result_path)
train_check_result = check_result(python_train_result_path)

print(f'# Original test case of test_check_result {count_test_case(python_test)}')
print(f'# Original test case of valid_check_result {count_test_case(python_valid)}')
print(f'# Original test case of train_check_result {count_test_case(python_train)}')

print(f'# Original Code pair of test_check_result {count_code(python_test)}')
print(f'# Original Code pair of valid_check_result {count_code(python_valid)}')
print(f'# Original Code pair of train_check_result {count_code(python_train)}')

gold_filter_test = data_filter(test_check_result, python_test)
gold_filter_valid = data_filter(valid_check_result, python_valid)
gold_filter_train = data_filter(train_check_result, python_train)

print(f'# Gold filtered test case of test_check_result {count_test_case(gold_filter_test)}')
print(f'# Gold filtered test case of valid_check_result {count_test_case(gold_filter_valid)}')
print(f'# Gold filtered test case of train_check_result {count_test_case(gold_filter_train)}')

print(f'# Gold filtered Code pair of test_check_result {count_code(gold_filter_test)}')
print(f'# Gold filtered Code pair of valid_check_result {count_code(gold_filter_valid)}')
print(f'# Gold filtered Code pair of train_check_result {count_code(gold_filter_train)}')


with open(f'./python_data/python_test_gold_filtered.json', 'w') as f:
    json.dump(gold_filter_test, f, indent=None)

with open(f'./python_data/python_valid_gold_filtered.json', 'w') as f:
    json.dump(gold_filter_valid, f, indent=None)

with open(f'./python_data/python_train_gold_filtered.json', 'w') as f:
    json.dump(gold_filter_train, f, indent=None)