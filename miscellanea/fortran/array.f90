PROGRAM ARRAY
    implicit none

    !These are static array
    integer :: i
    integer :: j
    integer, dimension(10) :: array1
    integer :: array2(10) = (/2,2,3,4,5,6,7,8,9,10/)
    integer :: arrayb(10) = [1,2,3,4,5,6,7, 8,9,10]
    real, dimension(10, 10) :: array2d
    !Allocatable Arrays
    integer, allocatable :: array3(:)

    print '(*(1I2))', array2
    array1(1:5)=1; !Make the 1 to five equal 1
    array1(6:)=2; !make 6 to the end equal 2
    ! PRint '(I0)', array1
    ! PRint '(I0)', array1(1:10:2)
    array1=[(i, i = 1,10)] !an implied do loop
    print *, "array1"
    PRint '(*(1I3))', array1
    print '(*(1I3))', array1(10: 1: -1) !print backwards
    allocate(array3(50))
     
    array3(:) = 10 
    print '(*(1I3))', array3
    deallocate(array3)

    

end program array
