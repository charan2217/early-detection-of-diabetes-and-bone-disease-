# Early Detection of Diabetes and Bone Disorders

This project focuses on the early detection of diabetes and bone disorders using machine learning and IoT-based data collection. The system processes sensor data, applies ML models, and provides insights for early diagnosis.

## 📌 Features
- **Machine Learning Model**: Uses KNN for classification.
- **IoT Integration**: Collects foot pressure and related health data.
- **Web Interface**: Displays predictions and reports.
- **ESP Microcontroller**: Manages sensor data communication.

## 🏗 Project Structure
```
├── app_1.html        # Web interface for data visualization
├── app_2.html        # Additional web UI components
├── data.csv          # Collected dataset for training/testing
├── ESP_Wahaj.h       # Header file for ESP microcontroller
├── final.py          # Main script for processing and inference
├── Foot_multiple_2025.ino # Arduino sketch for sensor integration
├── KNN.py            # KNN classification script
├── model.sav         # Pre-trained ML model
```

## 🔧 Setup & Installation
1. **Clone the repository**
   ```sh
   git clone https://github.com/yourusername/your-repo.git
   cd your-repo
   ```
2. **Install dependencies**
   ```sh
   pip install -r requirements.txt
   ```
3. **Run the application**
   ```sh
   python final.py
   ```

## 📊 Data Collection
- Sensor data is collected from foot pressure sensors and other health indicators.
- The `data.csv` file contains the training dataset.
- Processed data is sent to the ML model for prediction.

## 🤖 Machine Learning Model
- The project employs a **K-Nearest Neighbors (KNN)** model for classification.
- The model is pre-trained and stored in `model.sav`.
- Predictions are made in `final.py` and `KNN.py`.

## 🛠 Hardware Components
- **ESP Microcontroller**: Communicates with sensors.
- **Pressure Sensors**: Measures foot pressure changes.
- **DHT11**: Monitors temperature and humidity.
- **Piezoelectric Sensors**: Captures bone health indicators.

## 🚀 Future Enhancements
- Improve the ML model accuracy.
- Expand dataset for better predictions.
- Develop a mobile app for real-time monitoring.

## 🤝 Contributing
Feel free to contribute! Fork the repo, create a feature branch, and submit a PR.

## 📜 License
This project is open-source and available under the MIT License.
