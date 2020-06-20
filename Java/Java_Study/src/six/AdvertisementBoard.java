package six;

public class AdvertisementBoard {
    public void show(Advertisement advertisement){
        System.out.println(advertisement.getCorpName() + "的广告词如下：");
        advertisement.showAdvertisement();
    }
}
