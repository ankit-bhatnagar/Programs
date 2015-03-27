class Animal {
	public Animal() {
		System.out.println("Animal Constructor");
	}
}

class Dog extends Animal {
	public Dog() {
		System.out.println("Dog Constructor");
	}
}

public class MyFirstJavaProgram {

    public static void main(String []args) {
       System.out.println("Hello World");
       Dog a = new Dog();
    }
}