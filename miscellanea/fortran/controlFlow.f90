program controlFlow

  implicit none

  real :: angle
  character (len=16) :: chartmp
  integer :: i, j
  angle = 100

  if (angle < 90) then
    print *, "angle is acute"
  else if (angle <180) then
    print *, "angle is obtuse"
  else
    print *, "angle is reflex"
  end if

  do i = 1, 10 !1 to 10 inclusively
    print '(i3)', i
  end do

  do i = 0, 9
    do j = 1, 10 
      print '(i5)', i*10+j
   end do
  end do
  i = 0
  chartmp = "in do while loop"
  do while(i<11)
    i = i+1
    if (i==2) then
      cycle  ! equicalent to continue
    end if 
    if (i==5) then 
      exit
    end if
    print 100, chartmp, i
    100 format (20x, a, 3x, i3 )
  end do

end program controlFlow
