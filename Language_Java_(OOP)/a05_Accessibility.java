// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 29th December 2021

class Main{
    static {System.out.println("Main static 1");}
    public static void main(String args[]){
        System.out.println("Instanciating object1 of B...");
        B obj1 = new B();
        
        System.out.println("Instanciating object2 of B...");
        B obj2 = new B(3);

        System.out.println("Instanciating object3 of B...");
        B obj3 = new B(3,4);
    }
    static {System.out.println("Main static 2");}
    static {System.out.println("Main static 3");}
}

class A{
    static {System.out.println("A static 1");}
    A(){System.out.println("A constructor()");}
    static {System.out.println("A static 2");}
    A(int a){System.out.println("A constructor(int a)");}
    static {System.out.println("A static 3");}
    A(int a , int b){System.out.println("A constructor(int a , int b)");}
}

class B extends A{
    static {System.out.println("B static 1");}
    B(){System.out.println("B constructor()");}
    static {System.out.println("B static 2");}
    B(int a){System.out.println("B constructor(int a)");}
    static {System.out.println("B static 3");}
    B(int a , int b){System.out.println("B constructor(int a , int b)");}    
}
