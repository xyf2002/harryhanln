program string
    implicit none

    character(len=4)::firstName
    character(len=5)::lastName='Smith'
    character(len=10)::fullName
    character(:), allocatable :: longName(:)

    firstName = 'John'
    fullName=firstName//' '//lastName
    print *, "First Name: ", firstName
    print *, "Last Name: ", lastName
    print *, "Full Name: ", fullName


    longName = "HarrySmith" ! allocate automatically


end program string

