
# Advanced Matrix Algorithm

This is a C++ project developed as part of the **Problem Solving in Software Engineering** course. The goal of this project is to generate input and core matrices, calculate an output matrix based on a custom algorithm, and manage all data through a text file system.

---

## 📌 Features

- Generates random **input** and **core matrices**
- Calculates an **output matrix** using a custom convolution-like algorithm
- Reads/writes all matrices from/to a `data.txt` file
- Handles invalid user inputs
- Displays matrices in a clean, formatted console output
- Provides options to:
  - Generate new matrices
  - Read and calculate from existing file
  - Exit the program

---

## 🧠 Algorithm Overview

The algorithm applies a unique transformation by sliding the core matrix over the input matrix and applying a weighted sum. The output matrix is computed using the formula:

```
output(i, j) = ∑ (core * input) / (coreSize^2)
```

Where the input matrix indices are shifted based on the core position using:

```
input[rowOfOut - rowOfCore + coreSize - 1][colOfOut - colOfCore + coreSize - 1]
```

---

## 🛠️ Technologies Used

- **C++**
- Standard libraries:
  - `<iostream>`, `<fstream>`, `<string>` – file & string operations
  - `<iomanip>` – formatted output
  - `<ctime>` – random seed
  - `<cmath>` – math functions like `pow`

---

## 🗂️ Project Structure

```
Project.cpp     → Main source file containing all logic
data.txt        → Input/output file for storing matrices
```

---

## 🧪 How to Run

1. Compile the code using any C++ compiler:
   ```
   g++ Project.cpp -o MatrixApp
   ```
2. Run the executable:
   ```
   ./MatrixApp
   ```
3. Follow the on-screen instructions to generate or read matrices.

---

## 👤 Author

**Ukbe Taha Şahinkaya**  s

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).
