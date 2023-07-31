program array

  implicit none
  integer, dimension(10) :: array1
  integer :: array2(10)

  character(10) :: fullname
  
  array1(1:3) = [1,2,3]

  print *, array1(1:3)
  fullname = "harryhan"
  print *, fullname

end program array
