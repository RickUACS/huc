/* Signed left-shift is implementation-defined in C89 (and see
   DR#081), not undefined.  Bug 7284 from Al Grant (AlGrant at
   myrealbox.com).  */

/* { dg-options "-std=c89" } */

extern void abort (void);
extern void exit (int);

int
f (int n)
{
  return (n << 8) / (1 << 7);
}

volatile int x;// = 128;

int
main (void)
{
  x = 128;
  if (f(x) != -256)
    abort ();
  exit (0);
}
