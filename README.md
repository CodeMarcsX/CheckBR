# CheckBR

**CheckBR** is a simple console application written in **C** that validates **Brazilian CPF and CNPJ** numbers.  
It features an interactive and colorful terminal interface, removes punctuation automatically, and displays a stylish ASCII banner.

---

## ✨ Features

* **Document Validation:**
  Validates Brazilian documents:

  * **CPF:** 11 digits
  * **CNPJ:** 14 digits

* **Automatic Punctuation Removal:**
  Supports input with dots, dashes, and slashes.

* **Colorful Output:**
  Shows **valid** numbers in green and **invalid** numbers in red.

* **Interactive Interface:**
  Includes a cyan ASCII banner and clears the terminal screen automatically.

* **Cross-Platform:**
  Works on **Windows**, **Linux**, and **macOS**.

---

## ⬇️ Setup (Cloning the Repository)

Clone this repository from GitHub:

```bash
git clone https://github.com/CodeMarcsX/CheckBR.git
cd CheckBR
````

---

## 🛠️ How to Compile and Run

### Prerequisites

You need a **C compiler**, like **GCC** or **Clang**.

### Compilation

1. Save the source code as `main.c`.
2. Open your terminal or command prompt.
3. Compile the program:

```bash
gcc main.c -o main
```

### Execution

Run the program:

**On Linux/macOS:**

```bash
./main
```

**On Windows:**

```bash
.\main.exe
```

⚠️ If colors or characters appear broken on Windows, set UTF-8 mode first:
```bash
chcp 65001
```
---

## 🚀 Usage

1. The program clears the terminal and shows the banner.
2. Enter a **CPF** or **CNPJ** when prompted.
3. The program evaluates and displays whether it is **valid** or **invalid**.

**Example**

```
    ______/ /             __   ____  ____       
   / ____/ /_  ___  _____/ /__/ __ )/ __ '      
  / /   / __ '/ _ '/ ___/ //_/ __  / /_/ /      
 / /___/ / / /  __/ /__/ ,< / /_/ / _, _/       
 '____/_/ /_/'___/'___/_/|_/_____/_/ |_|        
===========================================     
        CheckBR - Document Validator
===========================================     

Enter the CPF or CNPJ: 529.982.247-25

Valid CPF!

```
