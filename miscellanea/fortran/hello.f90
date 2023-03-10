program hello
    use, intrinsic :: iso_fortran_env, only: sp=>real32, dp=>real64
    implicit none
    real(sp) :: more
    real(dp) :: float64

    integer :: amount
    logical :: yes
    real :: pi = 3.1415926
    complex :: i 
    character :: initial = "H.H"
    integer :: age
    integer :: year
    real :: radius
    real :: height
    real :: volume
    real :: area
    logical :: is_it_true=.true.
    
    print *, is_it_true

    more = 3.14159265358979_sp

    print *, more**2


    amount = 10
    i = (1, -1)
    yes = .true. 


    print *, 'Hello, World!'
    print *, 'The amount (integer) is:', amount
    print *, 'The value of yes (logical) is:', yes
    print *, 'The value of initial (character) is:', initial
    print *, 'The value of pi (real) is:', pi
    
    print *, 'What is your age?'
    ! read(*,*) age
    ! print *, 'We got', age
      print *, 'Enter cylinder base radius:'
  read(*,*) radius

  print *, 'Enter cylinder height:'
  read(*,*) height

  area = pi * radius**2
  volume = area * height

  print *, 'Cylinder radius is: ', radius
  print *, 'Cylinder height is: ', height
  print *, 'Cylinder base area is: ', area
  print *, 'Cylinder volume is: ', volume
end program hello
