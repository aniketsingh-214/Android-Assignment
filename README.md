
# Project Name : BookNest

BookNest is a Java-based mobile app that lets users browse and view detailed book information from a mock API, 
save their favorite books locally using Room for offline access, all structured with a clean MVVM architecture for maintainable and reactive UI.

## How to Set Up and Run This Android Project in VS Code

### Prerequisites

* Android Studio installed (for Android SDK, emulator, and build tools)
* Java JDK (version 11 or 17 recommended)
* Make sure these environment variables are set properly:

  * `JAVA_HOME` (points to your JDK folder)
  * `ANDROID_HOME` (points to your Android SDK folder)
* Android device connected or Android emulator ready

### Steps to Run the Project

1. Open the project folder in VS Code

   * Open VS Code → File → Open Folder → Select your Android project directory

2. Build the project
   Open the terminal inside VS Code and run:

   ```bash
   ./gradlew assembleDebug
   ```

   This compiles the app and generates the APK.

3. Install the APK on your device/emulator**
   Run:

   ```bash
   adb install -r app/build/outputs/apk/debug/app-debug.apk
   ```

   *Note: `adb` is part of Android SDK platform-tools.*

4. Run the app
   Open the emulator or connect your real Android device.
   The app should launch automatically after installation.
   If not, open the app manually on the device.

5. Start the Android emulator (if needed)
   List available emulators:

   ```bash
   emulator -list-avds
   ```

   Start emulator:

   ```bash
   emulator -avd <emulator_name>
   ```

C++ files to compile & run them:

1. Open a terminal (Command Prompt or PowerShell on Windows).

2. Compile your C++ code (`file.cpp`) into an executable:

   ```bash
   g++ file.cpp -o file.exe
   ```

3. Run the executable:

   ```bash
   ./file.exe
   ```






