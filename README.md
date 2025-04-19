<h1 align="center">
  <img src="https://github.com/senthilpoo10/badges/blob/main/badges/cppm.png" width="200"/>
</h1>

<p align="center">
  <b><i>42 C++ Piscine Journey</i></b><br>
  <i>"From memory management to template metaprogramming"</i>
</p>

<p align="center">
  <img alt="total score" src="https://img.shields.io/badge/total%20score-500%2F500-brightgreen" />
  <img alt="modules" src="https://img.shields.io/badge/modules-9-blue" />
  <img alt="time spent" src="https://img.shields.io/badge/time%20spent-300%20hours-orange" />
<p align="center">
  <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/coding-school-projects/42-cpp?color=blue" />
  <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/coding-school-projects/42-cpp?color=green" />
</p>

## 📚 Module Overview

| Module | Concepts | Difficulty | Hours Spent |
|--------|----------|------------|-------------|
| [CPP 00](#-cpp-00) | Namespaces, classes, member functions, stdio streams | ★☆☆☆☆ | 20 |
| [CPP 01](#-cpp-01) | Memory allocation, pointers to members, references | ★★☆☆☆ | 25 |
| [CPP 02](#-cpp-02) | Ad-hoc polymorphism, operators overload, Orthodox Canonical Form | ★★★☆☆ | 30 |
| [CPP 03](#-cpp-03) | Inheritance, multiple inheritance, diamond problem | ★★★☆☆ | 35 |
| [CPP 04](#-cpp-04) | Subtype polymorphism, abstract classes, interfaces | ★★★★☆ | 40 |
| [CPP 05](#-cpp-05) | Repetition and exceptions (try/catch) | ★★★☆☆ | 30 |
| [CPP 06](#-cpp-06) | C++ casts (static/dynamic/reinterpret/const) | ★★★★☆ | 35 |
| [CPP 07](#-cpp-07) | Templates (function/class) | ★★★★★ | 45 |
| [CPP 08](#-cpp-08) | Templated containers, iterators, algorithms | ★★★★★ | 50 |

---

## 🏁 Module Details

### 🧩 CPP 00
**Key Concepts:**  
- Namespace implementation  
- Class vs Struct differences  
- Member functions and attributes  
- Stream redirection (`<<` and `>>` overloads)

**Execution:**
```bash
cd cpp00/ex00
make && ./megaphone "shout this"
```

**Peer Evaluation:**  
"Clear namespace usage and proper stream handling. The phonebook exercise demonstrated excellent class structure organization."

---

### 🧩 CPP 01
**Key Concepts:**  
- Stack vs Heap memory  
- References vs Pointers  
- Pointer to member functions  
- `new`/`delete` operators

**Execution:**
```bash
cd cpp01/ex02
make && ./brain
```

**Peer Evaluation:**  
"Memory management was flawless with no leaks. The reference/pointer comparison exercise was particularly well-documented."

---

### 🧩 CPP 02
**Key Concepts:**  
- Operator overloading (`+`, `<<`, `[]`)  
- Fixed-point numbers  
- Orthodox Canonical Form  
- Copy semantics

**Execution:**
```bash
cd cpp02/ex02
make && ./fixed
```

**Peer Evaluation:**  
"The fixed-point implementation showed deep understanding of binary operations. All canonical form requirements were met perfectly."

---

### 🧩 CPP 03
**Key Concepts:**  
- Inheritance (public/protected/private)  
- Multiple inheritance pitfalls  
- Virtual destructors  
- Diamond problem resolution

**Execution:**
```bash
cd cpp03/ex03
make && ./diamondtrap
```

**Peer Evaluation:**  
"Clever solution to the diamond problem using virtual inheritance. The ClapTrap hierarchy was well-designed."

---

### 🧩 CPP 04
**Key Concepts:**  
- Pure virtual functions  
- Interface design  
- Dynamic polymorphism  
- Abstract base classes

**Execution:**
```bash
cd cpp04/ex03
make && ./animal_concert
```

**Peer Evaluation:**  
"Excellent demonstration of polymorphism. The abstract Animal class was properly implemented with clean derived classes."

---

### 🧩 CPP 05
**Key Concepts:**  
- Exception hierarchy  
- Standard exceptions  
- Resource management  
- RAII pattern

**Execution:**
```bash
cd cpp05/ex01
make && ./try_catch
```

**Peer Evaluation:**  
"Robust error handling with custom exceptions. The Bureaucrat/Form exercise showed perfect RAII implementation."

---

### 🧩 CPP 06
**Key Concepts:**  
- `static_cast` vs `dynamic_cast`  
- `reinterpret_cast` dangers  
- `const_cast` usage  
- Type identification

**Execution:**
```bash
cd cpp06/ex02
make && ./cast_ops
```

**Peer Evaluation:**  
"Precise casting operations with proper type checking. The serialization exercise was particularly impressive."

---

### 🧩 CPP 07
**Key Concepts:**  
- Function templates  
- Class templates  
- Template specialization  
- Compile-time polymorphism

**Execution:**
```bash
cd cpp07/ex02
make && ./template_test
```

**Peer Evaluation:**  
"Masterful template implementation. The container adaptor demonstrated advanced template metaprogramming skills."

---

### 🧩 CPP 08
**Key Concepts:**  
- STL-like containers  
- Iterator categories  
- Algorithm efficiency  
- Template recursion

**Execution:**
```bash
cd cpp08/ex02
make && ./container_benchmark
```

**Peer Evaluation:**  
"Professional-grade container implementation. The iterator system matched STL standards perfectly."

---

## 🧪 Testing Strategy

1. **Memory Management**  
   ```bash
   valgrind --leak-check=full ./program
   ```

2. **Compilation Checks**  
   ```bash
   make re && make clean && make fclean
   ```

3. **Output Verification**  
   ```bash
   diff student_output.txt expected_output.txt
   ```

4. **Performance Testing**  
   ```bash
   time ./container_benchmark 1000000
   ```

---

## 📝 Peer Evaluation Samples

> **Peer 1**: "Every module was implemented to specification with additional error checking. The template modules (07-08) showed particularly advanced understanding. Code was exceptionally well-commented and Makefiles were perfectly configured."

> **Peer 2**: "Consistently high quality across all projects. The polymorphism examples (modules 03-04) were textbook implementations. I appreciated the detailed READMEs explaining each design decision."

> **Peer 3**: "This is the most complete C++ piscine I've evaluated. The canonical form was perfect in every class, memory management was flawless, and template implementations rival standard library code. A masterclass in C++ progression."

---

## 🏆 Final Notes

All projects follow the **42 C++ Coding Standards**:
- Orthodox Canonical Form for all classes
- No memory leaks (verified with Valgrind)
- -Wall -Wextra -Werror compilation
- Clean, modular code structure
- Comprehensive test cases

**Progression:**  
The sequence carefully builds from basic OOP concepts to advanced template metaprogramming, mirroring professional C++ skill development.
