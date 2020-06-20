package nine.shiyan;

public class CalService {
    private boolean isSecondNum = false;
    private String lastOp;
    private String firstNum = "0";
    private String secondNum = "null";
    private double store;
    private String numString = "0123456789.";
    private String opString = "+-*/";

    public String catNum(String cmd, String text) {
        String result = cmd;
        // 如果text不等于0
        if (!"0".equals(text)) {
            if (isSecondNum) {
                isSecondNum = false;
            } else {
                result = text + cmd;
            }
        }
        if (result.indexOf(".") == 0) {
            result = "0" + result;
        }
        return result;
    }

    public String setOp(String cmd, String text) {
        this.lastOp = cmd;
        this.firstNum = text;
        this.secondNum = null;

        this.isSecondNum = true;
        return null;
    }

    public String cal(String text, boolean isPercent) {
        double secondResult = secondNum == null ? Double.valueOf(text)
                .doubleValue() : Double.valueOf(secondNum).doubleValue();

        //除数为0
        if(secondResult == 0 && this.lastOp.equals("/")){
            return "0";
        }

        //有%
        if(isPercent){
            secondResult = MyMath.multiply(Double.valueOf(firstNum), MyMath.divide(secondResult, 100));
        }
        if(this.lastOp.equals("+")){
            firstNum = String.valueOf(MyMath.add(Double.valueOf(firstNum),secondResult));
        }else if (this.lastOp.equals("-")) {
            firstNum = String.valueOf(MyMath.subtract(Double.valueOf(firstNum),secondResult));
        }else if (this.lastOp.equals("*")) {
            firstNum = String.valueOf(MyMath.multiply(Double.valueOf(firstNum),secondResult));
        }else if (this.lastOp.equals("/")) {
            firstNum = String.valueOf(MyMath.divide(Double.valueOf(firstNum),secondResult));
        }

        secondNum = secondNum == null ? text :secondNum;
        this.isSecondNum = true;
        return firstNum;
    }
    //求开方
    public String sqrt(String text){
        this.isSecondNum = true;
        return String.valueOf(Math.sqrt(Double.valueOf(text)));
    }
    //求倒数
    public String setReciprocal(String text){
        if (text.equals("0")){
            return text;
        }else{
            this.isSecondNum = true;
            return String.valueOf(MyMath.divide(1, Double.valueOf(text)));
        }
    }
    //存储
    public String mCmd(String cmd,String text){
        if(cmd.equals("M+")){
            store = MyMath.add(store, Double.valueOf(text));
        }else if (cmd.equals("MC")) {
            store = 0;
        }else if (cmd.equals("MR")) {
            isSecondNum = true;
            return String.valueOf(store);
        }else if (cmd.equals("MS")) {
            store = Double.valueOf(text).doubleValue();
        }
        return null;
    }

    public String backSpace(String text){
        return text.equals("0") || text.equals("") ? "0" :text.substring(0,text.length()-1);
    }

    public String setNegative(String text){
        if(text.indexOf("-") == 0){
            return text.substring(1,text.length());
        }else{
            return "-" + text;
        }
    }
    public String clearAll(){
        this.firstNum = "0";
        this.secondNum = null;
        return this.firstNum;
    }
    public String clear(String text){
        return "0";
    }

    public String callMethod(String cmd, String text){
        if(cmd.equals("C")){
            return clearAll();
        }else if(cmd.equals("CE")){
            return clear(text);
        }else if (cmd.equals("Back")) {
            return backSpace(text);
        }else if (numString.indexOf(cmd) != -1) {
            return catNum(cmd, text);
        }else if (opString.indexOf(cmd) != -1) {
            return setOp(cmd, text);
        }else if (cmd.equals("+/-")) {
            return setNegative(text);  //设置正负号
        }else if(cmd.equals("1/x")){
            return setReciprocal(text);
        }else if (cmd.equals("sqrt")) {
            return sqrt(text);
        }else if(cmd.equals("%")){
            return cal(text, true);
        }else if(cmd.equals("=")){
            return cal(text, false);
        }else {
            return mCmd(cmd, text);
        }
    }
}
