# Tour of Go

Hello World in Go

```go
// file helloWorld.go
// To compule go build helloWorld.go
// To run: go run helloWorld.go
// Warning: in go, source files is organized into package. We can also run source file by themselves and for anything more complicated we need packagee first.

// all go file start with package. A file compiled to be executed must start with package main
package main 

import (
    "fmt"
)

func main(){
    fmt.Println("Hello, World")
}
```

## How to run a go program: module and organisation

**Warning** Go's package and source file management is, to the least, verbose. Unlike most other languages, in go you can not use a one-liner such as "import ../example" to import symbols from another file. Instead, go has a full-grown package-module system. 

The lack of straight-forward importing system is because, from the beginning, 
> Go was developed for use by large teams working on million line programs ()[Quote](https://groups.google.com/g/golang-nuts/c/_BqV6Rk15UA/m/ns4y8jbxBgAJ))

### Package

Go's source files are organised into packages, which are files in the same directory that are compiled together. 
(They also need to be in the same package declared at top)
Files in **subdirectories** are excluded. 
All exported (i.e., names start with capital letter) are available to other source file in the same package without explicite import statements.


```
// file constant.go
package main

var Constant = 1 // start with capital C, exported by default
```

```
// file main.go
package main

import (
    "fmt"
)

func main (){
    fmt.Println(Constant)
}
```

Put the two files in the same directory. To run, `go run main.go constant.go` or `go build main.go`.

### Inter package 

To access files in different package, however, is a little more complicated, requiring to use go module.

Here is the setup:

1. Create go modules: `go mod init <modulename>`
2. Create file `main.go`, `util/key.go`

```go 
// main.go
package main

import (
    "fmt"
    "<modulename>/util"
)

func main(){
    fmt.Println(util.Key)
}
```

```go
// util/key.go

package util

const Key = 1
```
3. run `go build .`  .


### Decenterised publish


### Testing

Go has buildin `go test`

## Variable and type

Go's variable are typed. The declaration of typed is in reverse order as that of C.

```go
var i int = 10  // i is int 
j := 10 // j is assigned an inferred type. Only work within function
```

### Pointers 

Go has pointers, but no pointer arithmetics

```
i, j := 42, 2701
p := &i         // point to i
fmt.Println(*p)  //dereferencing
```

### Struct

```
type Vertex struct {
	X int
	Y int
}

func main() {
	fmt.Println(Vertex{1, 2})
}
```

Element of struct are accessed with `.` .

### Array

To create an array: 

```go
var s []int = []int{1,2,3,4}
c := []int{1,2,3,4}
```

Use make to create slide:

```
s := make([]int, 5)
s = append(s, 2, 3, 4) // append to slide
for i, v := range s {  // index and copy of element at index
    fmt.Printf("2**%d = %d\n", i, v)
}
```

### Map

```
type Vertex struct {
	Lat, Long float64
}


func main() {
	m: = make(map[string]Vertex)
	m["Bell Labs"] = Vertex{
		40.68433, -74.39967,
	}
	fmt.Println(m["Bell Labs"])  // 40.6 -74.3as
    delete(m, "Bell Labs") // delete from map

    elem, ok = m["Bell Labs"]  // test if key is present
}
```

### Function

Functions are first class object. They can be defined in other function and can be passed as variable to other functions.

```go
func double(a float64) float64 {
    return a*2
}
```

### Method

Go has no class. But go types can have method. Method is just function with a receiver.

```
type Vertex struct {
	X, Y float64
}

func (v Vertex) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func main(){
    v := Vertex{1,2}
    v.Abs()
}
```

By default, method and function take argument by value. They can also take arguments by pointer.

```
type Vertex struct {
	X, Y float64
}

func (v Vertex) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}
```

## Control Flow

### for

There is no need for () in go for loop, but the braces are required.

```go
for i:=1 ; i<100; i*=2 {
    println(i)
}
```

There is no __while__ in go. Use for instead:

```
for i<100 {
    i+=1
}
```

### if

Behaves the same as in C

### Switch

go switch are returned immediately after correct match.

### defer

A defer statement defers the execution of a function until the surrounding function returns. 

```
func main() {
	defer fmt.Println("world")
	fmt.Println("hello")
}
```

Defers can be stacked. First in, last out.
