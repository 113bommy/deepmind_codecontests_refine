# Google DeepMind Code Contests Dataset Refinement

Original Dataset - [Google DeepMind Code Contests](https://github.com/google-deepmind/code_contests)

To use this dataset more efficiently and precisely, we need to refine the datasets.

- Making pairs with correct solutions and incorrect solutions
- Creating pairs with correct and incorrect solutions.
- Filtering out correct code that fails private and public test cases.
- Filtering out incorrect code that passes all test cases.
- Choosing test cases that all the filtered correct code passes.
- Choosing test cases where the success rate of incorrect code is below 70%.

To create filtered datasets, follow the steps below.

## Dataset Curation
```bash
bash make_folder.sh
python -O dataset_curation.py
```
### Cpp correct solution execution
```bash
python -O cpp_test_gold_filter.py
python -O cpp_valid_gold_filter.py
python -O cpp_train_gold_filter.py
```
### Python3 correct solution execution
```bash
python -O python_test_gold_filter.py
python -O python_valid_gold_filter.py
python -O python_train_gold_filter.py
```
### Generating filtered Test case data w.r.t. Correct solution
```bash
python -O cpp_gold_filter.py
python -O python_gold_filter.py
```

### Cpp incorrect solution execution
```bash
python -O cpp_test_source_filter.py
python -O cpp_valid_source_filter.py
python -O cpp_train_source_filter.py
```
### Python3 incorrect solution execution
```bash
python -O python_test_source_filter.py
python -O python_valid_source_filter.py
python -O python_train_source_filter.py
```
### Generating filtered Test case data w.r.t. Incorrect solution
```bash
python -O cpp_source_filter.py
python -O python_source_filter.py
```
### Original Cpp Data
```python
# Original test case of test_check_result 2705635
# Original test case of valid_check_result 2119625
# Original test case of train_check_result 547494868
# Original Code pair of test_check_result 1664
# Original Code pair of valid_check_result 1406
# Original Code pair of train_check_result 146715
```
### Original Python Data
```python
# Original test case of test_check_result 2705635
# Original test case of valid_check_result 2119625
# Original test case of train_check_result 547494868
# Original Code pair of test_check_result 972
# Original Code pair of valid_check_result 876
# Original Code pair of train_check_result 280229
```

### Cpp gold filter result
```python
# Gold filtered test case of test_check_result 2399894
# Gold filtered test case of valid_check_result 1890493
# Gold filtered test case of train_check_result 124255504
# Gold filtered Code pair of test_check_result 1400
# Gold filtered Code pair of valid_check_result 1137
# Gold filtered Code pair of train_check_result 101083
```
### Python gold filter result
```python
# Gold filtered test case of test_check_result 1273884
# Gold filtered test case of valid_check_result 1167854
# Gold filtered test case of train_check_result 236025216
# Gold filtered Code pair of test_check_result 884
# Gold filtered Code pair of valid_check_result 805
# Gold filtered Code pair of train_check_result 236569
```
### Cpp Source filter result
```python
# source filtered test case of test_check_result 1432081
# source filtered test case of valid_check_result 1030536
# source filtered test case of train_check_result 33781912
# source filtered Code pair of test_check_result 1059
# source filtered Code pair of valid_check_result 848
# source filtered Code pair of train_check_result 72140
```
### Python Source filter result
```python
# source filtered test case of test_check_result 641695
# source filtered test case of valid_check_result 603286
# source filtered test case of train_check_result 17358456
# source filtered Code pair of test_check_result 577
# source filtered Code pair of valid_check_result 444
# source filtered Code pair of train_check_result 165132
```



Final data will be saved in *cpp_data* and *python_data* folder