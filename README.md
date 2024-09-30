# Algorithms PA#1
**Author**: Chia-Wen Fan  
**Date**: 2024/09/29

---

## SYNOPSIS:

```
NTU_sort -[IS|MS|BMS|QS|RQS|HS] <input_file_name> <output_file_name>
```

This program supports six different sorting methods:  
- **IS**: Insertion Sort  
- **MS**: Merge Sort  
- **BMS**: Bottom-up Merge Sort  
- **QS**: Quick Sort  
- **RQS**: Randomized Quick Sort  
- **HS**: Heap Sort  

---

## DIRECTORY STRUCTURE:

- **bin/**: Executable binary files  
- **doc/**: Reports  
- **inputs/**: Input data (unsorted)  
- **outputs/**: Output results (sorted)  
- **lib/**: Libraries  
- **src/**: Source C++ codes  
- **utility/**: Checker utilities  

---

## HOW TO COMPILE:

To compile the project, navigate to the root directory of this PA and run the following command:  
```
make
```

---

## HOW TO RUN:

1. Navigate to the `bin/` directory:  
   ```
   cd bin/
   ```

2. Execute the program with the following syntax:  
   ```
   ./NTU_sort -[IS|MS|BMS|QS|RQS|HS] <input_file_name> <output_file_name>
   ```

**Example**:  
If you're in the `b09303028_pa1` directory, run:  
```
./NTU_sort -MS inputs/1000.case1.in outputs/1000.case1.out
```

---

## HOW TO VERIFY THE RESULT:

1. Navigate to the `utility/` directory:  
   ```
   cd utility/
   ```

2. Run the result checker with the following syntax:  
   ```
   ./PA1_Result_Checker <input_file_name> <result_file_name>
   ```

**Example**:  
If you're in the `b09303028_pa1` directory, verify the result with:  
```
./PA1_Result_Checker ./inputs/5.case1.in ./outputs/5.case1.out
```

---

