# Typst: A type Setting System Like TeX

## Math mode

Inline equation are just like latex. For equation to be in separate line, put space between the dollar sign and the equation.

```typst
#set math.equation(numbering: "(1)")

Let $a$, $b$, and $c$ be the side of right triangle
Then, we know that:
$ a^2 + b^2 = c^2 $<Pathagorean's Theorem>

By @Pathagorean's Theorem, we know:
```

To label equation, include `#set math.equation(numbering: "(1)")` in file, label equation with `<label-name>` and reference it with @label-name.

## Latex Quick Guide

### Equivalent 

Quick command equivalence chart:

| Latex                         | typst                         |
| -----                         | -----                         |
|`$\displaystyle \frac{a}{b}$`  | `$display(a/b)`               |
|`$\epsilon$`                   | `$epsilon$                    |
|`\newpage`                     | `#pagebreak(weak: false)`     |
|`$\implies$                    | `$==>$`                       |
|`$\rightarrow`                 | `$->$`                        |

