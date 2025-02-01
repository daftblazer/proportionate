#include <gio/gio.h>

#if defined (__ELF__) && ( __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 6))
# define SECTION __attribute__ ((section (".gresource.com"), aligned (sizeof(void *) > 8 ? sizeof(void *) : 8)))
#else
# define SECTION
#endif

static const SECTION union { const guint8 data[5772]; const double alignment; void * const ptr;}  com_resource_data = {
  "\107\126\141\162\151\141\156\164\000\000\000\000\000\000\000\000"
  "\030\000\000\000\310\000\000\000\000\000\000\050\006\000\000\000"
  "\000\000\000\000\001\000\000\000\002\000\000\000\004\000\000\000"
  "\004\000\000\000\006\000\000\000\006\333\372\346\001\000\000\000"
  "\310\000\000\000\020\000\114\000\330\000\000\000\340\000\000\000"
  "\375\337\223\021\004\000\000\000\340\000\000\000\010\000\114\000"
  "\350\000\000\000\354\000\000\000\212\047\136\224\000\000\000\000"
  "\354\000\000\000\011\000\166\000\370\000\000\000\333\021\000\000"
  "\324\265\002\000\377\377\377\377\333\021\000\000\001\000\114\000"
  "\334\021\000\000\340\021\000\000\302\257\211\013\003\000\000\000"
  "\340\021\000\000\004\000\114\000\344\021\000\000\350\021\000\000"
  "\342\250\221\302\000\000\000\000\350\021\000\000\035\000\166\000"
  "\010\022\000\000\213\026\000\000\101\163\160\145\143\164\122\141"
  "\164\151\157\103\157\160\171\057\005\000\000\000\002\000\000\000"
  "\145\170\141\155\160\154\145\057\000\000\000\000\167\151\156\144"
  "\157\167\056\165\151\000\000\000\323\020\000\000\000\000\000\000"
  "\074\077\170\155\154\040\166\145\162\163\151\157\156\075\042\061"
  "\056\060\042\040\145\156\143\157\144\151\156\147\075\042\125\124"
  "\106\055\070\042\077\076\012\074\151\156\164\145\162\146\141\143"
  "\145\076\074\162\145\161\165\151\162\145\163\040\154\151\142\075"
  "\042\147\164\153\042\040\166\145\162\163\151\157\156\075\042\064"
  "\056\060\042\057\076\074\162\145\161\165\151\162\145\163\040\154"
  "\151\142\075\042\154\151\142\141\144\167\141\151\164\141\042\040"
  "\166\145\162\163\151\157\156\075\042\061\056\060\042\057\076\074"
  "\164\145\155\160\154\141\164\145\040\143\154\141\163\163\075\042"
  "\101\163\160\145\143\164\122\141\164\151\157\103\157\160\171\127"
  "\151\156\144\157\167\042\040\160\141\162\145\156\164\075\042\101"
  "\144\167\101\160\160\154\151\143\141\164\151\157\156\127\151\156"
  "\144\157\167\042\076\074\160\162\157\160\145\162\164\171\040\156"
  "\141\155\145\075\042\164\151\164\154\145\042\076\120\162\157\160"
  "\157\162\164\151\157\156\141\164\145\074\057\160\162\157\160\145"
  "\162\164\171\076\074\160\162\157\160\145\162\164\171\040\156\141"
  "\155\145\075\042\144\145\146\141\165\154\164\055\167\151\144\164"
  "\150\042\076\070\060\060\074\057\160\162\157\160\145\162\164\171"
  "\076\074\160\162\157\160\145\162\164\171\040\156\141\155\145\075"
  "\042\144\145\146\141\165\154\164\055\150\145\151\147\150\164\042"
  "\076\066\060\060\074\057\160\162\157\160\145\162\164\171\076\074"
  "\143\150\151\154\144\076\074\157\142\152\145\143\164\040\143\154"
  "\141\163\163\075\042\107\164\153\102\157\170\042\076\074\160\162"
  "\157\160\145\162\164\171\040\156\141\155\145\075\042\157\162\151"
  "\145\156\164\141\164\151\157\156\042\076\166\145\162\164\151\143"
  "\141\154\074\057\160\162\157\160\145\162\164\171\076\074\143\150"
  "\151\154\144\076\074\157\142\152\145\143\164\040\143\154\141\163"
  "\163\075\042\101\144\167\110\145\141\144\145\162\102\141\162\042"
  "\076\074\143\150\151\154\144\040\164\171\160\145\075\042\145\156"
  "\144\042\076\074\157\142\152\145\143\164\040\143\154\141\163\163"
  "\075\042\107\164\153\115\145\156\165\102\165\164\164\157\156\042"
  "\076\074\160\162\157\160\145\162\164\171\040\156\141\155\145\075"
  "\042\151\143\157\156\055\156\141\155\145\042\076\157\160\145\156"
  "\055\155\145\156\165\055\163\171\155\142\157\154\151\143\074\057"
  "\160\162\157\160\145\162\164\171\076\074\160\162\157\160\145\162"
  "\164\171\040\156\141\155\145\075\042\155\145\156\165\055\155\157"
  "\144\145\154\042\076\160\162\151\155\141\162\171\137\155\145\156"
  "\165\074\057\160\162\157\160\145\162\164\171\076\074\057\157\142"
  "\152\145\143\164\076\074\057\143\150\151\154\144\076\074\057\157"
  "\142\152\145\143\164\076\074\057\143\150\151\154\144\076\074\143"
  "\150\151\154\144\076\074\157\142\152\145\143\164\040\143\154\141"
  "\163\163\075\042\101\144\167\120\162\145\146\145\162\145\156\143"
  "\145\163\120\141\147\145\042\076\074\143\150\151\154\144\076\074"
  "\157\142\152\145\143\164\040\143\154\141\163\163\075\042\101\144"
  "\167\120\162\145\146\145\162\145\156\143\145\163\107\162\157\165"
  "\160\042\076\074\160\162\157\160\145\162\164\171\040\156\141\155"
  "\145\075\042\164\151\164\154\145\042\076\106\157\154\144\145\162"
  "\163\074\057\160\162\157\160\145\162\164\171\076\074\143\150\151"
  "\154\144\076\074\157\142\152\145\143\164\040\143\154\141\163\163"
  "\075\042\101\144\167\101\143\164\151\157\156\122\157\167\042\076"
  "\074\160\162\157\160\145\162\164\171\040\156\141\155\145\075\042"
  "\164\151\164\154\145\042\076\123\157\165\162\143\145\040\106\157"
  "\154\144\145\162\074\057\160\162\157\160\145\162\164\171\076\074"
  "\160\162\157\160\145\162\164\171\040\156\141\155\145\075\042\163"
  "\165\142\164\151\164\154\145\042\076\123\145\154\145\143\164\040"
  "\164\150\145\040\146\157\154\144\145\162\040\143\157\156\164\141"
  "\151\156\151\156\147\040\171\157\165\162\040\151\155\141\147\145"
  "\163\074\057\160\162\157\160\145\162\164\171\076\074\143\150\151"
  "\154\144\076\074\157\142\152\145\143\164\040\143\154\141\163\163"
  "\075\042\107\164\153\102\165\164\164\157\156\042\040\151\144\075"
  "\042\163\157\165\162\143\145\137\142\165\164\164\157\156\042\076"
  "\074\160\162\157\160\145\162\164\171\040\156\141\155\145\075\042"
  "\154\141\142\145\154\042\076\103\150\157\157\163\145\040\106\157"
  "\154\144\145\162\074\057\160\162\157\160\145\162\164\171\076\074"
  "\160\162\157\160\145\162\164\171\040\156\141\155\145\075\042\166"
  "\141\154\151\147\156\042\076\143\145\156\164\145\162\074\057\160"
  "\162\157\160\145\162\164\171\076\074\163\164\171\154\145\076\074"
  "\143\154\141\163\163\040\156\141\155\145\075\042\163\165\147\147"
  "\145\163\164\145\144\055\141\143\164\151\157\156\042\057\076\074"
  "\057\163\164\171\154\145\076\074\057\157\142\152\145\143\164\076"
  "\074\057\143\150\151\154\144\076\074\057\157\142\152\145\143\164"
  "\076\074\057\143\150\151\154\144\076\074\143\150\151\154\144\076"
  "\074\157\142\152\145\143\164\040\143\154\141\163\163\075\042\101"
  "\144\167\101\143\164\151\157\156\122\157\167\042\076\074\160\162"
  "\157\160\145\162\164\171\040\156\141\155\145\075\042\164\151\164"
  "\154\145\042\076\104\145\163\164\151\156\141\164\151\157\156\040"
  "\106\157\154\144\145\162\074\057\160\162\157\160\145\162\164\171"
  "\076\074\160\162\157\160\145\162\164\171\040\156\141\155\145\075"
  "\042\163\165\142\164\151\164\154\145\042\076\123\145\154\145\143"
  "\164\040\167\150\145\162\145\040\164\157\040\143\157\160\171\040"
  "\155\141\164\143\150\151\156\147\040\151\155\141\147\145\163\074"
  "\057\160\162\157\160\145\162\164\171\076\074\143\150\151\154\144"
  "\076\074\157\142\152\145\143\164\040\143\154\141\163\163\075\042"
  "\107\164\153\102\165\164\164\157\156\042\040\151\144\075\042\144"
  "\145\163\164\137\142\165\164\164\157\156\042\076\074\160\162\157"
  "\160\145\162\164\171\040\156\141\155\145\075\042\154\141\142\145"
  "\154\042\076\103\150\157\157\163\145\040\106\157\154\144\145\162"
  "\074\057\160\162\157\160\145\162\164\171\076\074\160\162\157\160"
  "\145\162\164\171\040\156\141\155\145\075\042\166\141\154\151\147"
  "\156\042\076\143\145\156\164\145\162\074\057\160\162\157\160\145"
  "\162\164\171\076\074\057\157\142\152\145\143\164\076\074\057\143"
  "\150\151\154\144\076\074\057\157\142\152\145\143\164\076\074\057"
  "\143\150\151\154\144\076\074\057\157\142\152\145\143\164\076\074"
  "\057\143\150\151\154\144\076\074\143\150\151\154\144\076\074\157"
  "\142\152\145\143\164\040\143\154\141\163\163\075\042\101\144\167"
  "\120\162\145\146\145\162\145\156\143\145\163\107\162\157\165\160"
  "\042\076\074\160\162\157\160\145\162\164\171\040\156\141\155\145"
  "\075\042\164\151\164\154\145\042\076\101\163\160\145\143\164\040"
  "\122\141\164\151\157\040\123\145\164\164\151\156\147\163\074\057"
  "\160\162\157\160\145\162\164\171\076\074\143\150\151\154\144\076"
  "\074\157\142\152\145\143\164\040\143\154\141\163\163\075\042\101"
  "\144\167\101\143\164\151\157\156\122\157\167\042\076\074\160\162"
  "\157\160\145\162\164\171\040\156\141\155\145\075\042\164\151\164"
  "\154\145\042\076\124\141\162\147\145\164\040\122\141\164\151\157"
  "\074\057\160\162\157\160\145\162\164\171\076\074\160\162\157\160"
  "\145\162\164\171\040\156\141\155\145\075\042\163\165\142\164\151"
  "\164\154\145\042\076\123\145\154\145\143\164\040\141\040\160\162"
  "\145\163\145\164\040\162\141\164\151\157\040\157\162\040\143\150"
  "\157\157\163\145\040\143\165\163\164\157\155\074\057\160\162\157"
  "\160\145\162\164\171\076\074\143\150\151\154\144\076\074\157\142"
  "\152\145\143\164\040\143\154\141\163\163\075\042\107\164\153\104"
  "\162\157\160\104\157\167\156\042\040\151\144\075\042\162\141\164"
  "\151\157\137\144\162\157\160\144\157\167\156\042\076\074\160\162"
  "\157\160\145\162\164\171\040\156\141\155\145\075\042\166\141\154"
  "\151\147\156\042\076\143\145\156\164\145\162\074\057\160\162\157"
  "\160\145\162\164\171\076\074\057\157\142\152\145\143\164\076\074"
  "\057\143\150\151\154\144\076\074\057\157\142\152\145\143\164\076"
  "\074\057\143\150\151\154\144\076\074\143\150\151\154\144\076\074"
  "\157\142\152\145\143\164\040\143\154\141\163\163\075\042\101\144"
  "\167\105\156\164\162\171\122\157\167\042\040\151\144\075\042\143"
  "\165\163\164\157\155\137\162\141\164\151\157\137\162\157\167\042"
  "\076\074\160\162\157\160\145\162\164\171\040\156\141\155\145\075"
  "\042\164\151\164\154\145\042\076\103\165\163\164\157\155\040\122"
  "\141\164\151\157\074\057\160\162\157\160\145\162\164\171\076\074"
  "\160\162\157\160\145\162\164\171\040\156\141\155\145\075\042\166"
  "\151\163\151\142\154\145\042\076\146\141\154\163\145\074\057\160"
  "\162\157\160\145\162\164\171\076\074\143\150\151\154\144\076\074"
  "\157\142\152\145\143\164\040\143\154\141\163\163\075\042\107\164"
  "\153\105\156\164\162\171\042\040\151\144\075\042\143\165\163\164"
  "\157\155\137\162\141\164\151\157\137\145\156\164\162\171\042\076"
  "\074\160\162\157\160\145\162\164\171\040\156\141\155\145\075\042"
  "\160\154\141\143\145\150\157\154\144\145\162\055\164\145\170\164"
  "\042\076\105\156\164\145\162\040\162\141\164\151\157\040\050\145"
  "\056\147\056\054\040\060\056\067\065\051\074\057\160\162\157\160"
  "\145\162\164\171\076\074\160\162\157\160\145\162\164\171\040\156"
  "\141\155\145\075\042\151\156\160\165\164\055\160\165\162\160\157"
  "\163\145\042\076\156\165\155\142\145\162\074\057\160\162\157\160"
  "\145\162\164\171\076\074\057\157\142\152\145\143\164\076\074\057"
  "\143\150\151\154\144\076\074\057\157\142\152\145\143\164\076\074"
  "\057\143\150\151\154\144\076\074\143\150\151\154\144\076\074\157"
  "\142\152\145\143\164\040\143\154\141\163\163\075\042\101\144\167"
  "\101\143\164\151\157\156\122\157\167\042\076\074\160\162\157\160"
  "\145\162\164\171\040\156\141\155\145\075\042\164\151\164\154\145"
  "\042\076\124\157\154\145\162\141\156\143\145\074\057\160\162\157"
  "\160\145\162\164\171\076\074\160\162\157\160\145\162\164\171\040"
  "\156\141\155\145\075\042\163\165\142\164\151\164\154\145\042\076"
  "\110\157\167\040\155\165\143\150\040\166\141\162\151\141\164\151"
  "\157\156\040\164\157\040\141\154\154\157\167\040\146\162\157\155"
  "\040\164\141\162\147\145\164\040\162\141\164\151\157\074\057\160"
  "\162\157\160\145\162\164\171\076\074\143\150\151\154\144\076\074"
  "\157\142\152\145\143\164\040\143\154\141\163\163\075\042\107\164"
  "\153\114\141\142\145\154\042\040\151\144\075\042\164\157\154\145"
  "\162\141\156\143\145\137\166\141\154\165\145\042\076\074\160\162"
  "\157\160\145\162\164\171\040\156\141\155\145\075\042\154\141\142"
  "\145\154\042\076\060\056\061\060\074\057\160\162\157\160\145\162"
  "\164\171\076\074\160\162\157\160\145\162\164\171\040\156\141\155"
  "\145\075\042\155\141\162\147\151\156\055\145\156\144\042\076\061"
  "\062\074\057\160\162\157\160\145\162\164\171\076\074\057\157\142"
  "\152\145\143\164\076\074\057\143\150\151\154\144\076\074\143\150"
  "\151\154\144\076\074\157\142\152\145\143\164\040\143\154\141\163"
  "\163\075\042\107\164\153\123\143\141\154\145\042\040\151\144\075"
  "\042\164\157\154\145\162\141\156\143\145\137\163\143\141\154\145"
  "\042\076\074\160\162\157\160\145\162\164\171\040\156\141\155\145"
  "\075\042\167\151\144\164\150\055\162\145\161\165\145\163\164\042"
  "\076\062\060\060\074\057\160\162\157\160\145\162\164\171\076\074"
  "\160\162\157\160\145\162\164\171\040\156\141\155\145\075\042\141"
  "\144\152\165\163\164\155\145\156\164\042\076\074\157\142\152\145"
  "\143\164\040\143\154\141\163\163\075\042\107\164\153\101\144\152"
  "\165\163\164\155\145\156\164\042\076\074\160\162\157\160\145\162"
  "\164\171\040\156\141\155\145\075\042\154\157\167\145\162\042\076"
  "\060\056\060\061\074\057\160\162\157\160\145\162\164\171\076\074"
  "\160\162\157\160\145\162\164\171\040\156\141\155\145\075\042\165"
  "\160\160\145\162\042\076\060\056\065\074\057\160\162\157\160\145"
  "\162\164\171\076\074\160\162\157\160\145\162\164\171\040\156\141"
  "\155\145\075\042\166\141\154\165\145\042\076\060\056\061\074\057"
  "\160\162\157\160\145\162\164\171\076\074\160\162\157\160\145\162"
  "\164\171\040\156\141\155\145\075\042\163\164\145\160\055\151\156"
  "\143\162\145\155\145\156\164\042\076\060\056\060\061\074\057\160"
  "\162\157\160\145\162\164\171\076\074\160\162\157\160\145\162\164"
  "\171\040\156\141\155\145\075\042\160\141\147\145\055\151\156\143"
  "\162\145\155\145\156\164\042\076\060\056\060\065\074\057\160\162"
  "\157\160\145\162\164\171\076\074\057\157\142\152\145\143\164\076"
  "\074\057\160\162\157\160\145\162\164\171\076\074\160\162\157\160"
  "\145\162\164\171\040\156\141\155\145\075\042\144\151\147\151\164"
  "\163\042\076\062\074\057\160\162\157\160\145\162\164\171\076\074"
  "\160\162\157\160\145\162\164\171\040\156\141\155\145\075\042\144"
  "\162\141\167\055\166\141\154\165\145\042\076\146\141\154\163\145"
  "\074\057\160\162\157\160\145\162\164\171\076\074\160\162\157\160"
  "\145\162\164\171\040\156\141\155\145\075\042\166\141\154\151\147"
  "\156\042\076\143\145\156\164\145\162\074\057\160\162\157\160\145"
  "\162\164\171\076\074\057\157\142\152\145\143\164\076\074\057\143"
  "\150\151\154\144\076\074\057\157\142\152\145\143\164\076\074\057"
  "\143\150\151\154\144\076\074\057\157\142\152\145\143\164\076\074"
  "\057\143\150\151\154\144\076\074\057\157\142\152\145\143\164\076"
  "\074\057\143\150\151\154\144\076\074\143\150\151\154\144\076\074"
  "\157\142\152\145\143\164\040\143\154\141\163\163\075\042\107\164"
  "\153\102\157\170\042\076\074\160\162\157\160\145\162\164\171\040"
  "\156\141\155\145\075\042\157\162\151\145\156\164\141\164\151\157"
  "\156\042\076\166\145\162\164\151\143\141\154\074\057\160\162\157"
  "\160\145\162\164\171\076\074\160\162\157\160\145\162\164\171\040"
  "\156\141\155\145\075\042\155\141\162\147\151\156\055\163\164\141"
  "\162\164\042\076\061\062\074\057\160\162\157\160\145\162\164\171"
  "\076\074\160\162\157\160\145\162\164\171\040\156\141\155\145\075"
  "\042\155\141\162\147\151\156\055\145\156\144\042\076\061\062\074"
  "\057\160\162\157\160\145\162\164\171\076\074\160\162\157\160\145"
  "\162\164\171\040\156\141\155\145\075\042\155\141\162\147\151\156"
  "\055\164\157\160\042\076\061\062\074\057\160\162\157\160\145\162"
  "\164\171\076\074\160\162\157\160\145\162\164\171\040\156\141\155"
  "\145\075\042\155\141\162\147\151\156\055\142\157\164\164\157\155"
  "\042\076\061\062\074\057\160\162\157\160\145\162\164\171\076\074"
  "\160\162\157\160\145\162\164\171\040\156\141\155\145\075\042\163"
  "\160\141\143\151\156\147\042\076\061\062\074\057\160\162\157\160"
  "\145\162\164\171\076\074\143\150\151\154\144\076\074\157\142\152"
  "\145\143\164\040\143\154\141\163\163\075\042\107\164\153\102\165"
  "\164\164\157\156\042\040\151\144\075\042\163\164\141\162\164\137"
  "\142\165\164\164\157\156\042\076\074\160\162\157\160\145\162\164"
  "\171\040\156\141\155\145\075\042\154\141\142\145\154\042\076\123"
  "\164\141\162\164\040\120\162\157\143\145\163\163\151\156\147\074"
  "\057\160\162\157\160\145\162\164\171\076\074\160\162\157\160\145"
  "\162\164\171\040\156\141\155\145\075\042\163\145\156\163\151\164"
  "\151\166\145\042\076\146\141\154\163\145\074\057\160\162\157\160"
  "\145\162\164\171\076\074\163\164\171\154\145\076\074\143\154\141"
  "\163\163\040\156\141\155\145\075\042\163\165\147\147\145\163\164"
  "\145\144\055\141\143\164\151\157\156\042\057\076\074\143\154\141"
  "\163\163\040\156\141\155\145\075\042\160\151\154\154\042\057\076"
  "\074\057\163\164\171\154\145\076\074\057\157\142\152\145\143\164"
  "\076\074\057\143\150\151\154\144\076\074\143\150\151\154\144\076"
  "\074\157\142\152\145\143\164\040\143\154\141\163\163\075\042\107"
  "\164\153\120\162\157\147\162\145\163\163\102\141\162\042\040\151"
  "\144\075\042\160\162\157\147\162\145\163\163\137\142\141\162\042"
  "\076\074\160\162\157\160\145\162\164\171\040\156\141\155\145\075"
  "\042\163\150\157\167\055\164\145\170\164\042\076\164\162\165\145"
  "\074\057\160\162\157\160\145\162\164\171\076\074\057\157\142\152"
  "\145\143\164\076\074\057\143\150\151\154\144\076\074\143\150\151"
  "\154\144\076\074\157\142\152\145\143\164\040\143\154\141\163\163"
  "\075\042\107\164\153\114\141\142\145\154\042\040\151\144\075\042"
  "\163\164\141\164\165\163\137\154\141\142\145\154\042\076\074\160"
  "\162\157\160\145\162\164\171\040\156\141\155\145\075\042\154\141"
  "\142\145\154\042\076\122\145\141\144\171\074\057\160\162\157\160"
  "\145\162\164\171\076\074\160\162\157\160\145\162\164\171\040\156"
  "\141\155\145\075\042\170\141\154\151\147\156\042\076\060\074\057"
  "\160\162\157\160\145\162\164\171\076\074\057\157\142\152\145\143"
  "\164\076\074\057\143\150\151\154\144\076\074\057\157\142\152\145"
  "\143\164\076\074\057\143\150\151\154\144\076\074\143\150\151\154"
  "\144\076\074\157\142\152\145\143\164\040\143\154\141\163\163\075"
  "\042\107\164\153\123\143\162\157\154\154\145\144\127\151\156\144"
  "\157\167\042\076\074\160\162\157\160\145\162\164\171\040\156\141"
  "\155\145\075\042\166\145\170\160\141\156\144\042\076\164\162\165"
  "\145\074\057\160\162\157\160\145\162\164\171\076\074\143\150\151"
  "\154\144\076\074\157\142\152\145\143\164\040\143\154\141\163\163"
  "\075\042\107\164\153\114\151\163\164\126\151\145\167\042\040\151"
  "\144\075\042\162\145\163\165\154\164\163\137\154\151\163\164\042"
  "\076\074\163\164\171\154\145\076\074\143\154\141\163\163\040\156"
  "\141\155\145\075\042\156\141\166\151\147\141\164\151\157\156\055"
  "\163\151\144\145\142\141\162\042\057\076\074\057\163\164\171\154"
  "\145\076\074\057\157\142\152\145\143\164\076\074\057\143\150\151"
  "\154\144\076\074\057\157\142\152\145\143\164\076\074\057\143\150"
  "\151\154\144\076\074\057\157\142\152\145\143\164\076\074\057\143"
  "\150\151\154\144\076\074\057\164\145\155\160\154\141\164\145\076"
  "\074\155\145\156\165\040\151\144\075\042\160\162\151\155\141\162"
  "\171\137\155\145\156\165\042\076\074\163\145\143\164\151\157\156"
  "\076\074\151\164\145\155\076\074\141\164\164\162\151\142\165\164"
  "\145\040\156\141\155\145\075\042\154\141\142\145\154\042\076\101"
  "\142\157\165\164\074\057\141\164\164\162\151\142\165\164\145\076"
  "\074\141\164\164\162\151\142\165\164\145\040\156\141\155\145\075"
  "\042\141\143\164\151\157\156\042\076\141\160\160\056\141\142\157"
  "\165\164\074\057\141\164\164\162\151\142\165\164\145\076\074\057"
  "\151\164\145\155\076\074\057\163\145\143\164\151\157\156\076\074"
  "\057\155\145\156\165\076\074\057\151\156\164\145\162\146\141\143"
  "\145\076\012\000\000\050\165\165\141\171\051\057\004\000\000\000"
  "\143\157\155\057\001\000\000\000\141\163\160\145\143\164\055\162"
  "\141\164\151\157\055\143\157\160\171\056\141\160\160\144\141\164"
  "\141\056\170\155\154\000\000\000\163\004\000\000\000\000\000\000"
  "\074\077\170\155\154\040\166\145\162\163\151\157\156\075\042\061"
  "\056\060\042\040\145\156\143\157\144\151\156\147\075\042\125\124"
  "\106\055\070\042\077\076\012\074\143\157\155\160\157\156\145\156"
  "\164\040\164\171\160\145\075\042\144\145\163\153\164\157\160\042"
  "\076\012\040\040\074\151\144\076\143\157\155\056\145\170\141\155"
  "\160\154\145\056\101\163\160\145\143\164\122\141\164\151\157\103"
  "\157\160\171\074\057\151\144\076\012\040\040\074\155\145\164\141"
  "\144\141\164\141\137\154\151\143\145\156\163\145\076\103\103\060"
  "\055\061\056\060\074\057\155\145\164\141\144\141\164\141\137\154"
  "\151\143\145\156\163\145\076\012\040\040\074\160\162\157\152\145"
  "\143\164\137\154\151\143\145\156\163\145\076\107\120\114\055\063"
  "\056\060\053\074\057\160\162\157\152\145\143\164\137\154\151\143"
  "\145\156\163\145\076\012\040\040\074\156\141\155\145\076\101\163"
  "\160\145\143\164\040\122\141\164\151\157\040\103\157\160\171\074"
  "\057\156\141\155\145\076\012\040\040\074\163\165\155\155\141\162"
  "\171\076\103\157\160\171\040\151\155\141\147\145\163\040\167\151"
  "\164\150\040\163\160\145\143\151\146\151\143\040\141\163\160\145"
  "\143\164\040\162\141\164\151\157\163\074\057\163\165\155\155\141"
  "\162\171\076\012\040\040\012\040\040\074\144\145\163\143\162\151"
  "\160\164\151\157\156\076\012\040\040\040\040\074\160\076\012\040"
  "\040\040\040\040\040\101\040\165\164\151\154\151\164\171\040\141"
  "\160\160\154\151\143\141\164\151\157\156\040\164\150\141\164\040"
  "\150\145\154\160\163\040\171\157\165\040\143\157\160\171\040\151"
  "\155\141\147\145\163\040\146\162\157\155\040\141\040\163\157\165"
  "\162\143\145\040\146\157\154\144\145\162\040\164\157\040\141\040"
  "\012\040\040\040\040\040\040\144\145\163\164\151\156\141\164\151"
  "\157\156\040\146\157\154\144\145\162\040\142\141\163\145\144\040"
  "\157\156\040\164\150\145\151\162\040\141\163\160\145\143\164\040"
  "\162\141\164\151\157\163\056\040\111\164\040\163\165\160\160\157"
  "\162\164\163\040\143\157\155\155\157\156\040\160\162\145\163\145"
  "\164\040\162\141\164\151\157\163\012\040\040\040\040\040\040\154"
  "\151\153\145\040\160\157\162\164\162\141\151\164\054\040\154\141"
  "\156\144\163\143\141\160\145\054\040\141\156\144\040\167\151\144"
  "\145\163\143\162\145\145\156\054\040\141\163\040\167\145\154\154"
  "\040\141\163\040\143\165\163\164\157\155\040\162\141\164\151\157"
  "\163\056\012\040\040\040\040\074\057\160\076\012\040\040\040\040"
  "\074\160\076\012\040\040\040\040\040\040\106\145\141\164\165\162"
  "\145\163\072\012\040\040\040\040\040\040\055\040\120\162\145\163"
  "\145\164\040\141\163\160\145\143\164\040\162\141\164\151\157\163"
  "\040\146\157\162\040\143\157\155\155\157\156\040\146\157\162\155"
  "\141\164\163\012\040\040\040\040\040\040\055\040\103\165\163\164"
  "\157\155\040\162\141\164\151\157\040\163\165\160\160\157\162\164"
  "\012\040\040\040\040\040\040\055\040\101\144\152\165\163\164\141"
  "\142\154\145\040\164\157\154\145\162\141\156\143\145\040\146\157"
  "\162\040\162\141\164\151\157\040\155\141\164\143\150\151\156\147"
  "\012\040\040\040\040\040\040\055\040\122\145\141\154\055\164\151"
  "\155\145\040\160\162\157\147\162\145\163\163\040\164\162\141\143"
  "\153\151\156\147\012\040\040\040\040\040\040\055\040\104\145\164"
  "\141\151\154\145\144\040\162\145\163\165\154\164\163\040\166\151"
  "\145\167\040\163\150\157\167\151\156\147\040\160\162\157\143\145"
  "\163\163\145\144\040\151\155\141\147\145\163\012\040\040\040\040"
  "\074\057\160\076\012\040\040\074\057\144\145\163\143\162\151\160"
  "\164\151\157\156\076\012\040\040\012\040\040\074\144\145\166\145"
  "\154\157\160\145\162\137\156\141\155\145\076\144\141\146\164\142"
  "\154\141\172\145\162\074\057\144\145\166\145\154\157\160\145\162"
  "\137\156\141\155\145\076\012\040\040\074\165\160\144\141\164\145"
  "\137\143\157\156\164\141\143\164\076\074\057\165\160\144\141\164"
  "\145\137\143\157\156\164\141\143\164\076\012\040\040\012\040\040"
  "\074\143\157\156\164\145\156\164\137\162\141\164\151\156\147\040"
  "\164\171\160\145\075\042\157\141\162\163\055\061\056\061\042\040"
  "\057\076\012\040\040\012\040\040\074\162\145\154\145\141\163\145"
  "\163\076\012\040\040\040\040\074\162\145\154\145\141\163\145\040"
  "\166\145\162\163\151\157\156\075\042\061\056\060\042\040\144\141"
  "\164\145\075\042\062\060\062\064\055\060\061\055\063\061\042\076"
  "\012\040\040\040\040\040\040\074\144\145\163\143\162\151\160\164"
  "\151\157\156\076\012\040\040\040\040\040\040\040\040\074\160\076"
  "\111\156\151\164\151\141\154\040\162\145\154\145\141\163\145\074"
  "\057\160\076\012\040\040\040\040\040\040\074\057\144\145\163\143"
  "\162\151\160\164\151\157\156\076\012\040\040\040\040\074\057\162"
  "\145\154\145\141\163\145\076\012\040\040\074\057\162\145\154\145"
  "\141\163\145\163\076\012\074\057\143\157\155\160\157\156\145\156"
  "\164\076\012\000\000\050\165\165\141\171\051" };

static GStaticResource static_resource = { com_resource_data.data, sizeof (com_resource_data.data) - 1 /* nul terminator */, NULL, NULL, NULL };

G_MODULE_EXPORT
GResource *com_get_resource (void);
GResource *com_get_resource (void)
{
  return g_static_resource_get_resource (&static_resource);
}
/* GLIB - Library of useful routines for C programming
 * Copyright (C) 1995-1997  Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Modified by the GLib Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GLib Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GLib at ftp://ftp.gtk.org/pub/gtk/.
 */

#ifndef __G_CONSTRUCTOR_H__
#define __G_CONSTRUCTOR_H__

/*
  If G_HAS_CONSTRUCTORS is true then the compiler support *both* constructors and
  destructors, in a usable way, including e.g. on library unload. If not you're on
  your own.

  Some compilers need #pragma to handle this, which does not work with macros,
  so the way you need to use this is (for constructors):

  #ifdef G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA
  #pragma G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(my_constructor)
  #endif
  G_DEFINE_CONSTRUCTOR(my_constructor)
  static void my_constructor(void) {
   ...
  }

*/

#ifndef __GTK_DOC_IGNORE__

#if  __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 7)

#define G_HAS_CONSTRUCTORS 1

#define G_DEFINE_CONSTRUCTOR(_func) static void __attribute__((constructor)) _func (void);
#define G_DEFINE_DESTRUCTOR(_func) static void __attribute__((destructor)) _func (void);

#elif defined (_MSC_VER)

/*
 * Only try to include gslist.h if not already included via glib.h,
 * so that items using gconstructor.h outside of GLib (such as
 * GResources) continue to build properly.
 */
#ifndef __G_LIB_H__
#include "gslist.h"
#endif

#include <stdlib.h>

#define G_HAS_CONSTRUCTORS 1

/* We do some weird things to avoid the constructors being optimized
 * away on VS2015 if WholeProgramOptimization is enabled. First we
 * make a reference to the array from the wrapper to make sure its
 * references. Then we use a pragma to make sure the wrapper function
 * symbol is always included at the link stage. Also, the symbols
 * need to be extern (but not dllexport), even though they are not
 * really used from another object file.
 */

/* We need to account for differences between the mangling of symbols
 * for x86 and x64/ARM/ARM64 programs, as symbols on x86 are prefixed
 * with an underscore but symbols on x64/ARM/ARM64 are not.
 */
#ifdef _M_IX86
#define G_MSVC_SYMBOL_PREFIX "_"
#else
#define G_MSVC_SYMBOL_PREFIX ""
#endif

#define G_DEFINE_CONSTRUCTOR(_func) G_MSVC_CTOR (_func, G_MSVC_SYMBOL_PREFIX)
#define G_DEFINE_DESTRUCTOR(_func) G_MSVC_DTOR (_func, G_MSVC_SYMBOL_PREFIX)

#define G_MSVC_CTOR(_func,_sym_prefix) \
  static void _func(void); \
  extern int (* _array ## _func)(void);              \
  int _func ## _wrapper(void);              \
  int _func ## _wrapper(void) { _func(); g_slist_find (NULL,  _array ## _func); return 0; } \
  __pragma(comment(linker,"/include:" _sym_prefix # _func "_wrapper")) \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) int (* _array ## _func)(void) = _func ## _wrapper;

#define G_MSVC_DTOR(_func,_sym_prefix) \
  static void _func(void); \
  extern int (* _array ## _func)(void);              \
  int _func ## _constructor(void);              \
  int _func ## _constructor(void) { atexit (_func); g_slist_find (NULL,  _array ## _func); return 0; } \
   __pragma(comment(linker,"/include:" _sym_prefix # _func "_constructor")) \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) int (* _array ## _func)(void) = _func ## _constructor;

#elif defined(__SUNPRO_C)

/* This is not tested, but i believe it should work, based on:
 * http://opensource.apple.com/source/OpenSSL098/OpenSSL098-35/src/fips/fips_premain.c
 */

#define G_HAS_CONSTRUCTORS 1

#define G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA 1
#define G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA 1

#define G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(_func) \
  init(_func)
#define G_DEFINE_CONSTRUCTOR(_func) \
  static void _func(void);

#define G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(_func) \
  fini(_func)
#define G_DEFINE_DESTRUCTOR(_func) \
  static void _func(void);

#else

/* constructors not supported for this compiler */

#endif

#endif /* __GTK_DOC_IGNORE__ */
#endif /* __G_CONSTRUCTOR_H__ */

#ifdef G_HAS_CONSTRUCTORS

#ifdef G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA
#pragma G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(comresource_constructor)
#endif
G_DEFINE_CONSTRUCTOR(comresource_constructor)
#ifdef G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA
#pragma G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(comresource_destructor)
#endif
G_DEFINE_DESTRUCTOR(comresource_destructor)

#else
#warning "Constructor not supported on this compiler, linking in resources will not work"
#endif

static void comresource_constructor (void)
{
  g_static_resource_init (&static_resource);
}

static void comresource_destructor (void)
{
  g_static_resource_fini (&static_resource);
}
