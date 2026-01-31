*This project has been created as part of the 42 curriculum by fcardozo.*

## Description
Push_swap is a sorting challenge that uses two stacks (A and B) and a limited instruction set to arrange integers in ascending order using the fewest possible moves. This implementation focuses on a clear, maintainable baseline strategy: it pushes elements from stack A to stack B until only three remain, sorts the trio, then reinserts the stored elements in the correct order.

## Instructions
1. **Dependencies**
   - GNU Make
   - GCC (or any compiler supporting `-W  all -Wextra -Werror`)
2. **Build**
   ```sh
   make
   ```
3. **Clean & Rebuild**
   ```sh
   make re
   ```
4. **Usage**
   ```sh
   ./push_swap 2 1 3 6 5 8
   ```
   The program outputs the sequence of stack operations on stdout. You can pipe it into `checker_linux` (available in `pstester/`) to validate correctness:
   ```sh
   ./push_swap 2 1 3 | ./checker_linux 2 1 3
   ```

## Resources
- [42 subject PDF](https://cdn.intra.42.fr/pdf/pdf/96071/en.subject.pdf) — official specification covering evaluation rules, grading, and allowed instructions.
- [Push_swap Visualizer by o-reo](https://github.com/o-reo/push_swap_visualizer) — helpful for understanding stack states as instructions are applied.
- [GEMARTIN tester](https://github.com/gemartin99/Push-Swap-Tester) — automated script for stress testing the solver on Linux and macOS.
- **AI usage**: ChatGPT/Cascade was used to (a) assist with rewriting the README to satisfy the new Chapter VII formatting requirements, and (b) previously aid in reverting chunk-based optimizations and restoring the baseline algorithmic flow. All generated content was reviewed and validated before inclusion.
