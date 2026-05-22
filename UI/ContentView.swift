import SwiftUI
struct ContentView: View {
    var body: some View {
        TabView {
            ScannerView()
                .tabItem { Image(systemName: "magnifyingglass"); Text("فحص") }
            ExploitGuideView()
                .tabItem { Image(systemName: "brain.head.profile"); Text("مرشد AI") }
            ToolsView()
                .tabItem { Image(systemName: "hammer.fill"); Text("أدوات") }
            RemoteView()
                .tabItem { Image(systemName: "antenna.radiowaves.left.and.right"); Text("تحكم") }
        }
    }
}
struct ExploitGuideView: View {
    @State private var cveInput = ""
    @State private var steps: [String] = []
    var body: some View {
        VStack {
            TextField("أدخل CVE (مثلاً CVE-2099-0001)", text: $cveInput)
                .textFieldStyle(RoundedBorderTextFieldStyle())
            Button("احصل على دليل الاستغلال") {
                steps = runPythonScript(cve: cveInput)
            }
            List(steps, id: \.self) { step in
                Text(step)
            }
        }
        .padding()
    }
    func runPythonScript(cve: String) -> [String] {
        // استدعاء exploit_wizard
        let task = Process()
        task.launchPath = "/usr/bin/python3"
        task.arguments = [Bundle.main.path(forResource: "architect_ai", ofType: "py")!, cve]
        let pipe = Pipe()
        task.standardOutput = pipe
        task.launch()
        let data = pipe.fileHandleForReading.readDataToEndOfFile()
        return String(data: data, encoding: .utf8)?.components(separatedBy: "\n") ?? []
    }
}
struct ScannerView: View {
    var body: some View { Text("واجهة المسح") }
}
struct ToolsView: View {
    var body: some View { Text("أدوات الهجوم") }
}
struct RemoteView: View {
    var body: some View { Text("التحكم عن بعد") }
}
