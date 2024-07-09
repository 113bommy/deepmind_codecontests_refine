from datasets import load_dataset
from tqdm import tqdm
from multiprocessing import Pool
import json
import Levenshtein


def data_align(description, public_case, private_case, gen_case, solution, incor_solution):
    data_dict = {}
    for index, (des, pub, priv, gen, sol, incor) in enumerate(zip(description, public_case, private_case, gen_case, solution.values(), incor_solution.values())):
        data_dict[index] = {
            'description': des,
            'test_case':{
                'public': pub,
                'private': priv,
                'generated': gen
            },
            'correct': sol,
            'incorrect': incor
        }
    return data_dict


def calculate_levenshtein_distance(s1, s2):
    return Levenshtein.distance(s1, s2)

def find_matching_pairs(data_dict):
    correct_codes = data_dict['correct']
    incorrect_codes = data_dict['incorrect']
    solution_paires = []

    for cor_code in correct_codes:
        for incor_code in incorrect_codes:
            distance = Levenshtein.distance(cor_code, incor_code)
            if (distance != 0) and (distance <= 9):
                solution_paires.append((cor_code, incor_code))

    del data_dict['correct']
    del data_dict['incorrect']
    data_dict['code_pair'] = solution_paires

    return data_dict

def process_item(item):
    key, value = item
    return key, find_matching_pairs(value)

def make_pair_dic(data_dict):
    items = list(data_dict.items())
    
    with Pool(120) as pool:
        results = list(tqdm(pool.imap(process_item, items), total=len(items)))
    
    for key, result in results:
        data_dict[key] = result
    
    return data_dict

ds = load_dataset("deepmind/code_contests")

description_test = ds['test']['description']
description_valid = ds['valid']['description']
description_train = ds['train']['description']

public_case_test = ds['test']['public_tests']
public_case_valid = ds['valid']['public_tests']
public_case_train = ds['train']['public_tests']

private_case_test = ds['test']['private_tests']
private_case_valid = ds['valid']['private_tests']
private_case_train = ds['train']['private_tests']

gen_case_test = ds['test']['generated_tests']
gen_case_valid = ds['valid']['generated_tests']
gen_case_train = ds['train']['generated_tests']

cpp_train_sol = {}
cpp_valid_sol = {}
cpp_test_sol = {}

python_train_sol = {}
python_valid_sol = {}
python_test_sol = {}

for index, pair_data in enumerate(ds['valid']['solutions']):
    if any(lang in [2, 3] for lang in pair_data['language']):
        cpp_save = []
        python_save = []
        for (lang, sol) in zip(pair_data['language'], pair_data['solution']):
            if lang == 2:
                cpp_save.append(sol)
            elif lang == 3:
                python_save.append(sol)

    cpp_valid_sol[index] = cpp_save
    python_valid_sol[index] = python_save

for index, pair_data in enumerate(ds['train']['solutions']):
    if any(lang in [2, 3] for lang in pair_data['language']):
        cpp_save = []
        python_save = []
        for (lang, sol) in zip(pair_data['language'], pair_data['solution']):
            if lang == 2:
                cpp_save.append(sol)
            elif lang == 3:
                python_save.append(sol)

    cpp_train_sol[index] = cpp_save
    python_train_sol[index] = python_save

for index, pair_data in enumerate(ds['test']['solutions']):
    if any(lang in [2, 3] for lang in pair_data['language']):
        cpp_save = []
        python_save = []
        for (lang, sol) in zip(pair_data['language'], pair_data['solution']):
            if lang == 2:
                cpp_save.append(sol)
            elif lang == 3:
                python_save.append(sol)

    cpp_test_sol[index] = cpp_save
    python_test_sol[index] = python_save

cpp_train_incor_sol = {}
cpp_valid_incor_sol = {}
cpp_test_incor_sol = {}

python_train_incor_sol = {}
python_valid_incor_sol = {}
python_test_incor_sol = {}

for index, pair_data in enumerate(ds['valid']['incorrect_solutions']):
    if any(lang in [2, 3] for lang in pair_data['language']):
        cpp_save = []
        python_save = []
        for (lang, sol) in zip(pair_data['language'], pair_data['solution']):
            if lang == 2:
                cpp_save.append(sol)
            elif lang == 3:
                python_save.append(sol)

    cpp_valid_incor_sol[index] = cpp_save
    python_valid_incor_sol[index] = python_save

for index, pair_data in enumerate(ds['train']['incorrect_solutions']):
    if any(lang in [2, 3] for lang in pair_data['language']):
        cpp_save = []
        python_save = []
        for (lang, sol) in zip(pair_data['language'], pair_data['solution']):
            if lang == 2:
                cpp_save.append(sol)
            elif lang == 3:
                python_save.append(sol)

    cpp_train_incor_sol[index] = cpp_save
    python_train_incor_sol[index] = python_save

for index, pair_data in enumerate(ds['test']['incorrect_solutions']):
    if any(lang in [2, 3] for lang in pair_data['language']):
        cpp_save = []
        python_save = []
        for (lang, sol) in zip(pair_data['language'], pair_data['solution']):
            if lang == 2:
                cpp_save.append(sol)
            elif lang == 3:
                python_save.append(sol)

    cpp_test_incor_sol[index] = cpp_save
    python_test_incor_sol[index] = python_save

assert len(description_valid) == len(cpp_valid_sol)
assert len(description_train) == len(cpp_train_sol)
assert len(description_test) == len(cpp_test_sol)
assert len(description_valid) == len(cpp_valid_incor_sol)
assert len(description_train) == len(cpp_train_incor_sol)
assert len(description_test) == len(cpp_test_incor_sol)

assert len(description_valid) == len(python_valid_sol)
assert len(description_train) == len(python_train_sol)
assert len(description_test) == len(python_test_sol)
assert len(description_valid) == len(python_valid_incor_sol)
assert len(description_train) == len(python_train_incor_sol)
assert len(description_test) == len(python_test_incor_sol)

cpp_train = data_align(description_train, public_case_train, private_case_train, gen_case_train, cpp_train_sol, cpp_train_incor_sol)
cpp_test = data_align(description_test, public_case_test, private_case_test, gen_case_test, cpp_test_sol, cpp_test_incor_sol)
cpp_valid = data_align(description_valid, public_case_valid, private_case_valid, gen_case_valid, cpp_valid_sol, cpp_valid_incor_sol)

python_train = data_align(description_train, public_case_train, private_case_train, gen_case_train, python_train_sol, python_train_incor_sol)
python_test = data_align(description_test, public_case_test, private_case_test, gen_case_test, python_test_sol, python_test_incor_sol)
python_valid = data_align(description_valid, public_case_valid, private_case_valid, gen_case_valid, python_valid_sol, python_valid_incor_sol)

print(f'# of C++ train data description: {len(cpp_train)}')
print(f'# of C++ valid data description: {len(cpp_valid)}')
print(f'# of C++ test data description: {len(cpp_test)}')

print(f'# of Python train data description: {len(python_train)}')
print(f'# of Python valid data description: {len(python_valid)}')
print(f'# of Python test data description: {len(python_test)}')


pair_cpp_valid = make_pair_dic(cpp_valid)
with open('./cpp_data/cpp_valid_refine.json', 'w') as f:
    json.dump(pair_cpp_valid, f, indent=4)

pair_cpp_train = make_pair_dic(cpp_train)
with open('./cpp_data/cpp_train_refine.json', 'w') as f:
    json.dump(pair_cpp_train, f)

pair_cpp_test = make_pair_dic(cpp_test)
with open('./cpp_data/cpp_test_refine.json', 'w') as f:
    json.dump(pair_cpp_test, f, indent=4)

pair_python_train = make_pair_dic(python_train)
with open('./python_data/python_train_refine.json', 'w') as f:
    json.dump(pair_python_train, f)

pair_python_test = make_pair_dic(python_test)
with open('./python_data/python_test_refine.json', 'w') as f:
    json.dump(pair_python_test, f, indent=4)

pair_python_valid = make_pair_dic(python_valid)
with open('./python_data/python_valid_refine.json', 'w') as f:
    json.dump(pair_python_valid, f, indent=4)
