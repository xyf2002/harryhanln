subroutine printMatrix(n, m, A)
  implicit none
  integer, intent (in) :: n  ! n,m,A are dummy variable
  integer, intent (in) :: m  ! dummy variable requires intend(in)
  integer, intent (in) :: A(n,m)  ! in means read only, out means write only, inout meawns read and write

  integer :: i 
  do i = 1,n 
    print *, A(i, 1:m)
  end do

end subroutine

function vector_norm(n, vec) result(norm) 
  implicit none
  integer, intent (in) :: n
  real, intent (in) :: vec(n)
  real :: norm

  norm = sqrt(sum(vec**2))

end function

program subroutine

  integer :: mat(5, 10)
  real, dimension(10) :: vector1
  real :: norm
  mat (:,:) = 0
  call printMatrix(5, 10, mat) !subroutine should be called

  vector1 = [1,2,3,4,5,6,7,8,9,10]
  norm = vector_norm(10, vector1)
  print *, norm



end program subroutine
