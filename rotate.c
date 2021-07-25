#define TEMPLATE	((unsigned int) 0x0)
#define TRANSFORM	((unsigned int) 0x1)

void naive_rotate(int *nms, int siz, int offset)
{
	int buf[siz];
	unsigned int index = 0;
	unsigned int template = 0;
	unsigned int transform = 1;
	if (offset > siz) {
		if ((offset % siz | 0))
			for (; offset > siz; offset-=siz);
		else	offset = siz;
	}
	for (; index < siz; index++) {
		if ((index + transform) + offset <= siz)

			/* index + transform + offset - transform */
			buf[index + offset] = *(nms + index);
		else

			/* index + transform + offset - siz - transform */
			buf[index + offset - siz] = *(nms + index);
	}
}
