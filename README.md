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
### Cpp gold filter result
```python
# Original test case of test_check_result 2705635
# Original test case of valid_check_result 2119625
# Original test case of train_check_result 547494868
# Original Code pair of test_check_result 1664
# Original Code pair of valid_check_result 1406
# Original Code pair of train_check_result 146715

# Gold filtered test case of test_check_result 2399894
# Gold filtered test case of valid_check_result 1890493
# Gold filtered test case of train_check_result 124255504
# Gold filtered Code pair of test_check_result 1400
# Gold filtered Code pair of valid_check_result 1137
# Gold filtered Code pair of train_check_result 101083
```
### Python gold filter result
```python
# Original test case of test_check_result 2705635
# Original test case of valid_check_result 2119625
# Original test case of train_check_result 547494868
# Original Code pair of test_check_result 972
# Original Code pair of valid_check_result 876
# Original Code pair of train_check_result 280229

# Gold filtered test case of test_check_result 1273884
# Gold filtered test case of valid_check_result 1167854
# Gold filtered test case of train_check_result 236025216
# Gold filtered Code pair of test_check_result 884
# Gold filtered Code pair of valid_check_result 805
# Gold filtered Code pair of train_check_result 236569
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

Final data is saved in *cpp_data* and *python_data* folder