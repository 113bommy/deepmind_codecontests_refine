# Google DeepMind Code Contests Dataset Refinement

Original Dataset - [Google DeepMind Code Contests](https://github.com/google-deepmind/code_contests)

To use this dataset more efficiently and precisely, we need to refine the datasets.

- Reformat cpp into clang format (google format) and python into pep8 format
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

Final data will be saved in *cpp_data* and *python_data* folder