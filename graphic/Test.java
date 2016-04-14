/*
 * Test.java
 * Copyright (C) 2016 linghutf <linghutf@pc>
 *
 * Distributed under terms of the MIT license.
 */

/**
 * 测试echo "1 2"|java Test
 */
import java.util.Scanner;

public class Test
{

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int a = scan.nextInt();
        int b = scan.nextInt();
        System.out.printf("%d,%d\n",a,b);
    }
}

