# Google DeepMind Code Contests Dataset Refinement

Original Dataset - [Google DeepMind Code Contests](https://github.com/google-deepmind/code_contests)

To use this dataset more efficiently and precisely, we need to refine the datasets.

- Making pairs with correct solutions and incorrect solutions
- Filtering the test cases that work with the descriptions

To create filtered datasets, follow the steps below.

## Dataset Curation
```bash
bash make_folder.sh
python -O dataset_curation.py
```
### Test case execution - Cpp correct solution
```bash
python -O cpp_test_filter.py
python -O cpp_valid_filter.py
python -O cpp_train_filter.py
```
### Test case execution - Python3 correct solution
```bash
python -O python_test_filter.py
python -O python_valid_filter.py
python -O python_train_filter.py
```
### Generating filteres Test case data - Correct solution
```bash
python -O cpp_exclude_test_case.py
python -O python_exclude_test_case.py
```

Final data is saved in cpp_data and python_data folder

아직 Correct solution에 대해서만 진행했습니다. 추후 Incorrect solution에 대해서도 필터링 진행할 예정입니다.