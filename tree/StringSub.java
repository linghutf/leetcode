/*
 * StringSub.java
 * Copyright (C) 2016 linghutf <linghutf@pc>
 *
 * Distributed under terms of the MIT license.
 */

public class StringSub
{
	public StringSub() {

	}

    public static void main(String[] args){
        String s ="123";

        System.out.println(s.substring(0,0));
        int i = s.lastIndexOf('3');
        System.out.println(s.lastIndexOf('3')+","+s.lastIndexOf('4'));
        System.out.println(s.substring(0,i));
    }
}

