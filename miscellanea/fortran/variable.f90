program variable

  implicit none 

  integer :: age 
  real :: pi
  complex :: frequency
  character :: initial
  logical :: OK

  pi = 3.1415
  frequency = (1,2)
  initial = "a"
  OK = .true.
  print *, OK

  print *, "please enter your age!"
  read(*,*) age

  print *, "Your age is", age
  print *, "Your age square is", age**2
  print *, "Your age doubled is", age*2
  print *, "Your age plus 2 is", age+2
  print *, "Your age divided by 3 is", age/3
  


end program variable
