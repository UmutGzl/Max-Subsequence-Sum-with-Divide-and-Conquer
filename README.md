# Max-Subsequence-Sum-with-Divide-and-Conquer
### Algoritma Analizi Ödev-2

Bu ödevde çözüm getirilen problem, bir dizinin içerisindeki ardışıl en yüksek toplamı olan alt kümesini bulan algoritmayı yazmaktır. Problem, bize kazı yapan bir madencinin maksimum verimi elde etmesi adına kazanç değerlerini tutan bir ardışık dizide nereden başlayarak nereye kadar giderek maksimum kazanç sağlanacağının bulunması metaforu ile verilmiştir. Ancak problemin temel noktası, bir başlangıç ve bitiş noktası belirlenip bu iki nokta arasındaki kazancın maksimum olmasının sağlanmasıdır. Bu noktada “brute force” ve “divide and conquer” tasarım mantıkları kullanılarak 2 adet algoritma tasarlanmıştır.

#### Brute Force:

Brute force yaklaşım, bir algoritmanın çözümü için akla gelen ilk yöntemin
kullanılması anlamına gelmektedir. Bu noktada problem bir başlangıç ve bitiş noktasının ve aralığın bulunmasını içerdiğinden ilk akla gelen çözüm, her başlangıç noktası için dizide tarama yapılarak bir maksimum değerinin her artışta güncellenmesi üzerinedir. Bu da 2 adet iç içe for döngüsü anlamına gelmektedir.


#### Divide and Conquer: 

Divide and conquer metodu, problemin parçalara ayrılarak çözümlenmesi anlamına gelmektedir. Genellikle recursive olarak çözümlenir. Bu doğrultuda problemimiz 2 farklı fonksiyona ayrılır:
- Problemi parçalayan fonksiyon →MaxGain
- bulunan aşamada hesaplama yapan → CalculateMaxSum
MaxGain fonksiyonunda problem 2’ye bölünür ve sağ ve sol olarak 2 problem haline gelir. Sağ, sol ve o anki durumun toplam değerinin en büyüğü max olarak seçilir.

Recursive fonksiyonlar için bir durma noktasına ihtiyacımız vardır. Bu senaryoda ise 2 adet durma noktamız vardır:
- end < start, hatalı bir durum oluşturduğundan -1 değeri döndürülerek hem sonucu
etkilememesi hem de programın hata ile karşılaşmaması sağlanır.
- end=start durumunda ise orta değer döndürülür.


###### Anlatım Video Linki: https://youtu.be/d-ypmaVAG1U