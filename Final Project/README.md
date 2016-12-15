#Contents
Rand.py<br/>
	Two functions and a few lines to be executed while running, to produce randomly generated numbers.<br/>
	def nextPrime(seed)<br/>
		Returns the next prime number after seed (an integer).<br/>
		While it took a while to get the logic just right, writing this was much more straightforward than the random number generator.<br/>
	def random(number_to_generate, seed)<br/>
		Prints out random numbers.<br/>
		I took the middle square approach, but with a few prime numbers added (and multiplied) for good measure. I have not been able to find any loops/patterns in the current iteration. Coming up with something that didn't get stuck depleting itself out with zeroes or absurdly huge numbers was a lot harder than making a big number and taking a hunk of out the middle seems. But it works now.<br/>

#Usage
Run rand.py. You will be prompted to give a seed (this can be any integer), and how many numbers you want to generate (this must be positive). It will print out the numbers it generates. 
