package eight;

import java.util.Scanner;

public class Example8_8 {
    public static void main(String[] args) {
        String sourceString = "今晚十点进攻";
        EncryptAndDecrypt person = new EncryptAndDecrypt();
        System.out.println("输入密码加密：" + sourceString);
        Scanner scanner = new Scanner(System.in);
        String password = scanner.nextLine();
        String secret = person.encrypt(sourceString, password);
        System.out.println("密文：" + secret);
        System.out.println("输入解密密码");
        password = scanner.nextLine();
        String source = person.decrypt(secret, password);
        System.out.println("明文：" + source);
    }
}

class EncryptAndDecrypt{
    String encrypt(String sourceString, String password) {
        char[] p = password.toCharArray();
        int n = p.length;
        char[] c = sourceString.toCharArray();
        int m = c.length;
        for (int i=0; i<m; i++) {
            int mima = c[i] + p[i%n];
            c[i] = (char) mima;
        }
        return new String(c);
    }

    String decrypt(String sourceString, String password) {
        char[] p = password.toCharArray();
        int n = p.length;
        char[] c = sourceString.toCharArray();
        int m = c.length;
        for (int k=0; k<m; k++) {
            int mima = c[k] - p[k%n];
            c[k] = (char) mima;
        }
        return new String(c);
    }
}
