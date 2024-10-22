# Compile and Testing Python Script 💻

`test_c_programs.py` is a Python script designed to compile C programs and run them against predefined test cases. It provides detailed logs in the terminal and generates `.log` files for easy access to test results.

---

## Features

- **Compile C Programs**: Automatically compiles specified C programs.
- **Test Execution**: Runs C programs against test cases.
- **Logging**: Generates terminal logs and `.log` files for easy access to test results.

---

## Getting Started

### 1. Copy the Script

Ensure the `test_c_programs.py` script is placed in the root directory of your project, **not** inside any subfolder.

---

### 2. Configuration

Make sure the script is in the same directory as the C programs you want to test.

#### a. Folder-based Program Mapping:

For C programs stored inside a folder, use this format:

`"Folder_Name/Program.c": "Test_Case_Directory"`

For C programs stored directly in the root directory, use this format:

`"Program.c": "Test_Case_Directory"`

Here is an example configuration

```python



# ------------------------ Configuration -------------------- #
# Define your C programs and their corresponding test case directories here.
# Format: "C_PROGRAM_PATH": "TEST_CASE_DIRECTORY"

mappings = {
    "Program_folder/Program.c": "test_cases",  # Example folder-based mapping
    "Program.c": "test_cases",                 # Example single program mapping
    # Add more mappings as needed, e.g.,
    # "AnotherProgram/AnotherProgram.c": "tc_hw2",
}
# ------------------------- Configuration --------------------- #


```
---

### 3. Running the Script

To run the script, use one of the following methods:

#### a. Using Python 3 directly:

`python3 test_c_programs.py`

#### b. Making the script executable:

`chmod +x test_c_programs.py`

`./test_c_programs.py`

---

### Notes
- **Script**: Location: Make sure test_c_programs.py is in the same directory as your C programs.
- **Logs**: Logs will be displayed in the terminal and saved as .log files for future reference.
- **Test Case Mappings**:Double-check that your mappings are configured correctly before running the script.

---

### Prerequisites
- **Python**: Ensure you have Python 3 installed. The script is compatible with Python 3.x versions.
- **C Compiler**: A C compiler like gcc is required to compile the C programs.
- **Required Python Libraries**: No external Python libraries are required beyond the standard library.

---

### Contact
For any questions or suggestions, feel free to reach out:

- **Email**: prenticetang@gmail.com
- **LinkedIn**: linkedin.com/in/prentice-tang
- **GitHub**: github.com/prentang

---

### Acknowledgments
- Inspired by various automated testing scripts.
- Thanks to the open-source community for their invaluable resources.
- Big shoutout to mom for supporting my academia and continued growth.

---

Happy Coding! 🎉
