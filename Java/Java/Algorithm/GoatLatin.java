package Algorithm;

public class GoatLatin {
    private String toGoatLatin(String S){
        String[] str = S.split(" ");
            String res = "";
            for(int i=0;i<str.length;i++){
                if(str[i].startsWith("a")||str[i].startsWith("e")||str[i].startsWith("i")
                        ||str[i].startsWith("o")||str[i].startsWith("u")||str[i].startsWith("A")
                        ||str[i].startsWith("E")||str[i].startsWith("I")||str[i].startsWith("O")
                        ||str[i].startsWith("U")){
                    str[i] += "ma";
                }
            else {
                str[i] = str[i].substring(1) + str[i].substring(0,1) + "ma";
            }
            for(int j=0;j<i+1;j++){
                str[i] += "a";
            }
            res += str[i];
            if(i != str.length-1){
                res += " ";
            }
        }
        return res;
    }

    public static void main(String[] args){
        String b;
        GoatLatin a = new GoatLatin();
        b = a.toGoatLatin("asd");
        System.out.println(b);
    }
}
