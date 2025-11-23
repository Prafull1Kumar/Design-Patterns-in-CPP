// Traffic Light State interface
interface TrafficLightState {
    void nextState(TrafficLightContext context);
    String getColor();
}

// ------ Red State ------
class RedState implements TrafficLightState {
    @Override
    public void nextState(TrafficLightContext context) {
        context.setState(new GreenState());
    }

    @Override
    public String getColor() {
        return "Red";
    }
}

// ------ Green State ------
class GreenState implements TrafficLightState {
    @Override
    public void nextState(TrafficLightContext context) {
        context.setState(new YellowState());
    }

    @Override
    public String getColor() {
        return "Green";
    }
}

// ------ Yellow State ------
class YellowState implements TrafficLightState {
    @Override
    public void nextState(TrafficLightContext context) {
        context.setState(new RedState());
    }

    @Override
    public String getColor() {
        return "Yellow";
    }
}

// ------ Traffic Light Context ------
class TrafficLightContext {
    private TrafficLightState state;

    public TrafficLightContext() {
        this.state = new RedState();
    }

    public void setState(TrafficLightState state) {
        this.state = state;
    }

    public void next() {
        state.nextState(this);
    }

    public String getColor() {
        return state.getColor();
    }
}

// ------ Main Class ------
public class Main {
    public static void main(String[] args) {
        TrafficLightContext trafficLight = new TrafficLightContext();

        trafficLight.next();
        System.out.println(trafficLight.getColor());

        trafficLight.next();
        System.out.println(trafficLight.getColor());

        trafficLight.next();
        System.out.println(trafficLight.getColor());

        trafficLight.next();
        System.out.println(trafficLight.getColor());
    }
}
