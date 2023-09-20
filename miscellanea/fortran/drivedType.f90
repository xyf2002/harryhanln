program type

  ! like a class in c++
  type :: t_pair
    integer :: i = 1
    real    :: r = 0.3 ! the defalt value
  end type t_pair

  type(t_pair) :: pair
  type(t_pair) :: pair2
  pair%i = 2 ! % to access the component
  pair%r = 1.0
  
  ! print pair 
  print *, pair
  print *, pair2
  

end program
