#include <iostream>

struct A {
  void foo() { std::cout << "A::foo()\n"; }
  void bar() { std::cout << "A::bar()\n"; }
};

struct B : A {
  void foo() { std::cout << "B::foo()\n"; }
  virtual void bar() { std::cout << "B::bar()\n"; }
};

struct C : B {
  virtual void foo() { std::cout << "C::foo()\n"; }
  void bar() { std::cout << "C::bar()\n"; }
};

struct D : C {
  virtual void foo() { std::cout << "D::foo()\n"; }
  virtual void bar() { std::cout << "D::bar()\n"; }
};

struct E : D {
  virtual void foo() { std::cout << "E::foo()\n"; }
};

struct F : E {
  virtual void bar() { std::cout << "F::bar()\n"; }
};

struct G : F {
  void foo() { std::cout << "G::foo()\n"; }
};

struct H : G {
  void bar() { std::cout << "H::bar()\n"; }
};

struct I : H {};

#define TEST(obj) { obj.foo(); obj.bar(); }

int main() {
  A a; B b; C c; D d; E e; F f; G g; H h; I i;
  std::cout << "A a; B b; C c; D d; E e; F f; G g; H h; I i;\n";
  TEST(a); TEST(b); TEST(c); TEST(d); TEST(e); TEST(f); TEST(g); TEST(h); TEST(i);
  A &pb = b, &pc = c, &pd = d, &pe = e, &pf = f, &pg = g, &ph = h, &pi = i;
  std::cout << "A &pb = b, &pc = c, &pd = d, &pe = e, &pf = f, &pg = g, &ph = h, &pi = i;\n";
  TEST(pb); TEST(pc); TEST(pd); TEST(pe); TEST(pf); TEST(pg); TEST(ph); TEST(pi);
  B &bc = c, &bd = d, &be = e, &bf = f, &bg = g, &bh = h, &bi = i;
  std::cout << "B &bc = c, &bd = d, &be = e, &bf = f, &bg = g, &bh = h, &bi = i;\n";
  TEST(bc); TEST(bd); TEST(be); TEST(bf); TEST(bg); TEST(bh); TEST(bi);
  C &cd = d, &ce = e, &cf = f, &cg = g, &ch = h, &ci = i;
  std::cout << "C &cd = d, &ce = e, &cf = f, &cg = g, &ch = h, &ci = i;\n";
  TEST(cd); TEST(ce); TEST(cf); TEST(cg); TEST(ch); TEST(ci);
  D &de = e, &df = f, &dg = g, &dh = h, &di = i;
  std::cout << "D &de = e, &df = f, &dg = g, &dh = h, &di = i;\n";
  TEST(de); TEST(df); TEST(dg); TEST(dh); TEST(di);
  E &ef = f, &eg = g, &eh = h, &ei = i;
  std::cout << "E &ef = f, &eg = g, &eh = h, &ei = i;\n";
  TEST(ef); TEST(eg); TEST(eh); TEST(ei);
  F &fg = g, &fh = h, &fi = i;
  std::cout << "F &fg = g, &fh = h, &fi = i;\n";
  TEST(fg); TEST(fh); TEST(fi);
  G &gh = h, &gi = i;
  std::cout << "G &gh = h, &gi = i;\n";
  TEST(gh); TEST(gi);
  H &hi = i;
  std::cout << "H &hi = i;\n";
  TEST(hi);
  return 0;
}

