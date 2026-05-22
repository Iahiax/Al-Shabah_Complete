#!/usr/bin/env python3
import json, sys
class ShadowGuide:
    def __init__(self):
        with open('../Core/cve_database_2099.json','r') as f:
            self.exploits = json.load(f)
    def analyze(self, cve):
        for e in self.exploits:
            if e['cve'] == cve:
                return e
        return None
    def guide(self, cve):
        exp = self.analyze(cve)
        if not exp:
            return ["لا توجد معلومات عن هذه الثغرة"]
        steps = [f"💥 استغلال: {exp['name']}", f"📋 الوصف: {exp['description']}"]
        steps.append(f"🎯 الأنظمة: {', '.join(exp['os'])}")
        steps.append(f"🔧 المتطلبات: {exp['requires']}")
        steps.append(f"📂 ملف الاستغلال: {exp['exploit_path']}")
        steps.append("1. تأكد من اتصالك بالهدف.")
        if exp['port'] > 0:
            steps.append(f"2. افحص المنفذ {exp['port']}.")
        steps.append(f"3. نفذ {exp['exploit_path']}.")
        steps.append(f"4. استمتع بـ {exp['post']}.")
        return steps
if __name__ == '__main__':
    guide = ShadowGuide()
    if len(sys.argv) > 1:
        print('\n'.join(guide.guide(sys.argv[1])))
