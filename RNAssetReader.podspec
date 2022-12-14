
Pod::Spec.new do |s|
  s.name         = "RNAssetReader"
  s.version      = "0.0.2"
  s.summary      = "RNAssetReader"
  s.description  = <<-DESC
  RNAssetReader
  DESC
  s.homepage     = "ibitcy.com"
  s.license      = "MIT"
  s.author             = { "author" => "author@domain.cn" }
  s.platform     = :ios, "9.3"
  s.source       = { :git => "https://git.eoadm.com/stepan.kopylov/react-native-expertoption-mobile-socket.git", :tag => "master" }
  s.source_files  = "ios/RNAssetReader/*.{h,m,mm}", "cpp/*.{hpp,cpp,h,c}"
  s.dependency 'React'
	s.dependency "ReactCommon"
end

