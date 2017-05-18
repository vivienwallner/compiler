Copyright (c) 2015-2016, the Selfie Project authors. All rights reserved. Please see the AUTHORS file for details. Use of this source code is governed by a BSD license that can be found in the LICENSE file.

Selfie is a project of the Computational Systems Group at the Department of Computer Sciences of the University of Salzburg in Austria. For further information and code please refer to:

http://selfie.cs.uni-salzburg.at

This is the grammar of the C Star (C\*) programming language.

C\* is a small Turing-complete subset of C that includes dereferencing (the `*` operator) but excludes data structures, bitwise and Boolean operators, and many other features. C\* is supposed to be close to the minimum necessary for implementing a self-compiling, single-pass, recursive-descent compiler.

C\* Keywords: `int`, `while`, `if`, `else`, `return`, `void`

C\* Symbols: `=`, `+`, `-`, `*`, `/`, `%`, `==`, `!=`, `<`, `<<`, `<=`, `>`, `>>`, `>=`,  `&`, `|`, `~` , `,`, `(`, `)`, `{`, `}`, `;`, integer, identifier, character, string

with:

```

integer    = digit { digit } .

identifier = letter { letter | digit | "_" } .

character  = "'" printable_character "'" .

string     = """ { printable_character } """ .
```

and:

```
binaryDigit = "0" | "1" .

octalDigit = "0" | ... | "7" .

hexDigit = "0" | ... | "9" | "A" |...| "F" .

digit  =  "0" | ... | "9" .

letter = "a" | ... | "z" | "A" | ... | "Z" .
```

C\* Grammar:

```
cstar            = { type identifier [ "=" [ cast ] [ "-" ] literal ]  ";" |        
                   ( "void" | type ) identifier procedure | type identifier { selector } ";" |
                      "struct" identifier ( "*" identifier | struct ) ";" } .

type             = ( "int" [ "*" ] ) .

struct          = "{" { ( type | "struct" identifier "*" ) identifier ";" } "}" .

cast             = "(" type ")" .

literal          = integer | character .

procedure        = "(" [ variable { "," variable } ] ")"
                    ( ";" | "{" { variable ";" } { statement } "}" ) .

selector  =   "[" simpleExpression "]"  .

variable         =  type identifier .

statement        = call ";" | while | if | return ";" |
                   ( [ "*" ] identifier |  identifier selector | "*" "(" expression ")" )
                     "=" expression ";" .

call             = identifier "(" [ expression { "," expression } ] ")" .

expression      = comparisonExpression { ( "&" | "|" ) comparisonExpression } .

comparisonExpression  = shiftExpression { ( "==" | "!=" | "<" | ">" | "<=" | ">=" ) shiftExpression } .

shiftExpression   = simpleExpression { ( "<<" | ">>" )  simpleExpression } .

simpleExpression = [ "-" ] term { ( "+" | "-" ) term } .

term             =  factor { ( "*" | "/" | "%" ) factor } .

factor           = [ cast ]
                    (  [ "*" | "~" ] ( identifier selector | "(" expression ")" ) |
                      call |
                     literal |
                      string ) .

while            = "while" "(" expression ")"
                             ( statement |
                               "{" { statement } "}" ) .

if               = "if" "(" expression ")"
                             ( statement |
                               "{" { statement } "}" )
                         [ "else"
                             ( statement |
                               "{" { statement } "}" ) ] .

return           = "return" [ expression ] .
```
