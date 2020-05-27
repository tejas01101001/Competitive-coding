unsigned int rng_seed=69;
inline unsigned int rng() {
	rng_seed^=rng_seed<<13;
	rng_seed^=rng_seed>>17;
	rng_seed^=rng_seed<<5;
	return rng_seed;
}

int uni(int n)
{
    return (rng()%n);
}