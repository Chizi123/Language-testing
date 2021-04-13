      module llist
      type llelm
      integer :: n;
      type(llelm), pointer :: next;
      end type llelm
      end module

      program main
      use llist
      integer is_prime, i, max
      character(len=32) :: arg
      type(llelm), pointer :: l, e, c
      allocate(l)
      l%n = 2
      nullify(l%next)
      e => l
c      print *, 2

      call get_command_argument(1,arg)
      if (len_trim(arg) == 0) then
         max = huge(max)
      else
         read (arg,'(I32)') max
      end if
      do i = 3,max,2
         is_prime = 1;
         c => l
         do while(associated(c))
            if (c%n**2 <= i) then
               if (mod(i,c%n) == 0) then
                  is_prime = 0
                  exit
               end if
            else
               exit
            end if
            c => c%next
         end do
         if (is_prime == 1) then
            allocate(e%next)
            e => e%next
            e%n = i
            nullify(e%next)
c            print *, i
         endif
      end do
      do
         if (associated(l)) then
            e => l
            l => l%next
            deallocate(e)
         else
            exit
         end if
      end do
      end program main
