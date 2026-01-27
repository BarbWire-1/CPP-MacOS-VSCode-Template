# macOS Notes for C++ Course (VS Code & zsh)

I created this setup to follow the C++ course referenced here:
[freeCodeCamp C++ Programming Course](https://www.youtube.com/watch?v=8jLOx1hD3_o)

On **macOS**, there are a few differences compared to Windows/PowerShell in the shell commands and the build process.
So after installing all the compilerRelated stuff via hombrew:

---

## 1. Shell & File Listing

macOS uses **zsh**, not PowerShell:

* Commands like `dir` do not exist.
* To list files and directories (including hidden ones) in the workspace:

  ```zsh
  ls -lhA
  ```
* Optional alias to mimic PowerShell `dir` per session:

  ```zsh
  alias dir='ls -lhA'
  ```

---

## 2. Binary Naming & Running

macOS builds differ from Windows:

| Shell / OS  | Binary Type                                                | How to Run     |
| ----------- | ---------------------------------------------------------- | -------------- |
| zsh / macOS | Standard build task binary (e.g., `rooster`)               | `./rooster`    |
| zsh / macOS | Per-file build binary (e.g., `${fileBasenameNoExtension}`) | `./<filename>` |

* macOS **does not produce `.exe` files**.
* Always prepend `./` to run a binary in the current directory.

---

## 3. Compiler & Toolchain

* **Xcode Command Line Tools** must be installed:

  ```zsh
  xcode-select --install
  ```
* VS Code build tasks (.vscode/tasks.json) handle compilation automatically; you do **not** need to type compiler commands, but might want to change pats or naming of the created build to your liking.
* Alternative compilers (Homebrew LLVM/clang, GNU g++) can be used in tasks.
* For Homebrew Clang, `-isysroot ${SDKROOT}` ensures SDK headers are found; Apple Clang and g++ generally do not require it.

---

## 4. SDKROOT Notes

* Apple Clang: usually no `-isysroot` needed.
* Homebrew LLVM/clang: `-isysroot ${SDKROOT}` recommended.
* GNU g++: ignores `-isysroot` unless explicitly configured.

---

## 5. Typical VS Code Workflow

1. Use the **build task** (per-file or full project).
2. Executable appears in workspace folder.
3. Run in zsh:

   ```zsh
   ./<binary-name>
   ```
4. List workspace contents:

   ```zsh
   ls -lhA
   ```

---

## Summary

| Concept          | macOS Behavior                                                       |
| ---------------- | -------------------------------------------------------------------- |
| Shell            | zsh (not PowerShell)                                                 |
| Listing files    | `ls -lhA` or `dir` alias                                             |
| Binary name      | Standard: `program` / Per-file: `<filename>`                         |
| Running programs | `./binary-name`                                                      |
| Compiler         | Handled automatically by VS Code build tasks                         |
| SDKROOT          | Used only for Homebrew Clang; Apple Clang / g++ usually not required |
