<p align="center">
  <a>
    <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/8d/42_Logo.svg/1200px-42_Logo.svg.png" alt="Logo" width="200" height="200">
  </a>

  <p align="center">
    A bit of fun with UNIX<br>
    Project pipex of 42 school
    <br />
	</p>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Makefile-8A2BE2">
  <img src="https://img.shields.io/badge/C-4682B4">
  <img src="https://img.shields.io/badge/Shell-2E8B57">
  <img src="https://img.shields.io/badge/Gcc-00FF00">
  
</p>

## &#x1F4CC; Index 
- [What is pipex?](#-what-is-pipex)
- [Logic](#-logic)
- [Usage](#-usage)
- [Examples](#-examples)

## &#x2728; What is pipex?

The purpose of this project is the discovery and recreate in detail UNIX mechanism - `pipe() , fork(), dup2() and execve()` command in C.

Basically recreate:
```bash
< infile cat | wc -l > outfile
```

Bonus recreate:
```bash
< infile cat | command | ... | wc -l > outfile
```

## 🛠 Logic

Global logic of the project without bonus:
```bash
# ./pipex infile cmd1 cmd2 outfile
pipe()
 |
 |-- fork()
 :    |
 :    |-- child 1 // cmd1
 :    |--dup2( stdout -> pipe[stdout] )
 :    |--execve(cmd1)
 :
 |-- fork()
      |
      |-- child 2 // cmd2
      |--dup2(pipe[stdin] -> stdin )
      |--close end[stdout]
      |--execve(cmd2)
 :
 :-- parent process
 :
 return;
```
Reading from `infile`, execute `cmd1` with `infile` as input, send the output to `cmd2`, which will write to `outfile`.

```bash
# each cmd needs a stdin (input) and returns an output (to stdout)
   
    infile                                             outfile
as stdin for cmd1                                 as stdout for cmd2            
       |                        PIPE                        ↑
       |           |---------------------------|            |
       ↓             |                       |              |
      cmd1   -->    end[1]       ↔       end[0]   -->     cmd2           
                     |                       |
            cmd1   |---------------------------|  end[0]
           output                             reads end[1]
         is written                          and sends cmd1
          to end[1]                          output to cmd2
       (end[1] becomes                      (end[0] becomes 
        cmd1 stdout)                           cmd2 stdin)
```

## &#x1F4BB; Usage

`make` to compile the executable.

`make bonus` to compile the executable with multiple pipes.

`make clean` remove .o files.

`make fclean` remove .o files and .a files and executable.

## &#x1F4D6; Examples

The arguments of the executable should be:
```bash
./pipex infile cmd1 cmd2 cmd3 ... outfile
```

Execute in the terminal something like:

<img width="678" alt="Screen Shot 2024-03-07 at 6 35 55 PM" src="https://github.com/vcereced/pipex/assets/120835200/f9aeb2a6-148a-4c4b-b817-17f7d565099b">



