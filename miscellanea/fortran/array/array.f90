PROGRAM ARRAY
    implicit none

    integer, dimension(10) :: array1
    integer :: array2(10)
    real, dimension(10, 10) :: array2d
    array1(1:5)=1; !Make the 1 to five equal 1
    array1(6:)=2; !make 6 to the end equal 2
    ! PRint '(I0)', array1
    PRint '(I0)', array1(1:10:2)

end program array
