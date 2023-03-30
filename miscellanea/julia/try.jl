find_gcd = gcd ∘ collect ∘ extrema 

# create a random list
rand_list = rand(5:20, 4)
#print the list
println(rand_list)
# find the gcd
println(find_gcd(rand_list))
