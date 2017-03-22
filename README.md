
the cryptopals crypto challenges

If you're not that familiar with crypto already, or if your familiarity comes 
mostly from things like Applied Cryptography, this fact may surprise you: most 
crypto is fatally broken. The systems we're relying on today that aren't known 
to be fatally broken are in a state of just waiting to be fatally broken. 
Nobody is sure that TLS 1.2 or SSH 2 or OTR are going to remain safe as designed.

The current state of crypto software security is similar to the state of software
security in the 1990s. Specifically: until around 1995, it was not common
knowledge that software built by humans might have trouble counting. As a result,
nobody could size a buffer properly, and humanity incurred billions of dollars
in cleanup after a decade and a half of emergency fixes for memory corruption
vulnerabilities.

Counting is not a hard problem. But cryptography is. There are just a few things
you can screw up to get the size of a buffer wrong. There are tens, probably
hundreds, of obscure little things you can do to take a cryptosystem that
should be secure even against an adversary with more CPU cores than there are
atoms in the solar system, and make it solveable with a Perl script and 15
seconds. Don't take our word for it: do the challenges and you'll see.

People "know" this already, but they don't really know it in their gut, and we
think the reason for that is that very few people actually know how to implement
the best-known attacks. So, mail us, and we'll give you a tour of them.
