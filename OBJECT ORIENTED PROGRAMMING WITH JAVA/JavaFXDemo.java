import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class JavaFXDemo extends Application {
    private int count = 0;

    @Override
    public void start(Stage primaryStage) {
        Label label = new Label("Button not clicked yet.");
        Button button = new Button("Click Me!");

        button.setOnAction(e -> {
            count++;
            label.setText("Button clicked " + count + " times.");
        });

        VBox vbox = new VBox(10, label, button);
        vbox.setStyle("-fx-padding: 20; -fx-alignment: center;");

        Scene scene = new Scene(vbox, 300, 150);
        primaryStage.setTitle("JavaFX Demo");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
