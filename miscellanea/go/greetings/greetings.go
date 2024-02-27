package greetings

import "fmt"

// Hello returns a greeting from a named person
func Hello(name string) string {
	message := fmt.Sprintf("Hi, %v, welcome!", name)
	return message
}


