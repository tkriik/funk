Command line
------------

### Version

    $ funk -V

### Help

    $ funk -h

### Read from stdin

    $ funk

## Read from File

    $ funk foo.fu


Design
------

  - asserts everywhere
  - enums start at 1
  - fail on errors (err(3))
  - vertical programming
  - pass objects by value


Virtual machine
---------------

### Data types

#### Internal

  - jmp

#### Read from source

  - word

#### Parsed from words

  - builtin
  - integer

#### Initial code

  1. READ
  2. EVAL
  3. JMP 0
