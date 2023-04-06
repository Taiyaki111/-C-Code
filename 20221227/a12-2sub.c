void myitoa(int val, char *buf)
{
	char *p;
	char *firstdig;
	char temp;
	unsigned int digval;
	unsigned int u_val;

	p = buf;

	if (val < 0) {
		/* Negative, so output '-' and negate */
		*p++ = '-';
		u_val = (unsigned int)(- val);
	} else {
		u_val = (unsigned int) val;
	}
	
	/* Save pointer to first digit */
	firstdig = p;

	do {
		digval = u_val % 10;
		u_val /= 10;

		/* Convert to ascii and store */
		if (digval > 9) {
			*p++ = (char) (digval - 10 + 'a');
		} else {
			*p++ = (char) (digval + '0');
		}
	} while (u_val > 0);

	/* 
	 * We now have the digit of the number in the buffer, but in reverse
	 * order.  Thus we reverse them now.
	 */
	*p-- = '\0';
	do {
		temp = *p;
		*p = *firstdig;
		*firstdig = temp;
		p--;
		firstdig++;
	} while (firstdig < p);
}
