package six;

public class BlackLandCorp implements Advertisement {
    @Override
    public void showAdvertisement() {
        System.out.println("***************");
        System.out.println("activity");
        System.out.println("***************");
    }

    @Override
    public String getCorpName() {
        return "黑土集团";
    }
}
