import java.time.LocalTime;

public class InterProcess{
    public static int x=0;
    public static class Request implements Runnable{
        public void run(){
            System.out.println("What is the time now ? \n");
                try {
                    Thread.sleep(1000);
                } catch (Exception e) {
                    // TODO: handle exception
                }
                x=1;
        }
    }
    public static class Response implements Runnable{
        public void run(){
            while(x==0){
                try {
                    Thread.sleep(1000);
                } catch (Exception e) {
                    // TODO: handle exception
                }
                System.out.println("Time is : "+LocalTime.now());
            }
        }
    }
    public static void main(String[] args) throws Exception{
        Thread request = new Thread(new Request());
        Thread response = new Thread(new Response());
        request.start();
        response.start();
    }
}